/* MCP41010 Digitally Controlled Potentiometer example of ESP-IDF
 *
 * This sample code is in the public domain.
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "esp_log.h"

#include "mcp41010.h"

#define TAG "MAIN"

void app_main()
{
#if CONFIG_MODEL_MCP41010
	ESP_LOGI(TAG, "MCP41010");
	float total= KOHMS_MCP41010;
#elif CONFIG_MODEL_MCP41050
	ESP_LOGI(TAG, "MCP41050");
	float total= KOHMS_MCP41050;
#elif CONFIG_MODEL_MCP41100
	ESP_LOGI(TAG, "MCP41100");
	float total= KOHMS_MCP41100;
#elif CONFIG_MODEL_MCP42010
	ESP_LOGI(TAG, "MCP42010");
	float total= KOHMS_MCP42010;
#elif CONFIG_MODEL_MCP42050
	ESP_LOGI(TAG, "MCP42050");
	float total= KOHMS_MCP42050;
#elif CONFIG_MODEL_MCP42100
	ESP_LOGI(TAG, "MCP42100");
	float total= KOHMS_MCP42100;
#endif

	ESP_LOGI(TAG, "total=%f KOhms", total);
	ESP_LOGI(TAG, "CONFIG_MOSI_GPIO=%d", CONFIG_MOSI_GPIO);
	ESP_LOGI(TAG, "CONFIG_SCLK_GPIO=%d", CONFIG_SCLK_GPIO);
	ESP_LOGI(TAG, "CONFIG_CS_GPIO=%d", CONFIG_CS_GPIO);

	MCP_t dev;
	MCP41_begin(&dev, CONFIG_MOSI_GPIO, CONFIG_SCLK_GPIO, CONFIG_CS_GPIO, total);

	uint8_t cur_value = 0;
	uint8_t DIRECTION = 1;
	uint8_t potentiometer = METER_BOTH;
	while(1) {
		MCP41_setWiper(&dev, cur_value, potentiometer);
		float resistance = MCP41_getK(&dev, cur_value);
		ESP_LOGI(TAG, "cur_value=%d resistance=%f KOhms", cur_value, resistance);
		if(DIRECTION) {
			cur_value++;
			if(cur_value == 0) DIRECTION = 0;
		} else {
			cur_value--;
			if(cur_value == 0) DIRECTION = 1;
		}
		vTaskDelay(20);
	} // end while
}

