/*
    Copyright 2021 Picovoice Inc.

    You may not use this file except in compliance with the license. A copy of the license is located in the "LICENSE"
    file accompanying this source.

    Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on
    an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the
    specific language governing permissions and limitations under the License.
*/

#include <Picovoice_EN.h>
#include "params.h"
#include <Arduino_APDS9960.h>

#define MEMORY_BUFFER_SIZE (70 * 1024)

static const char* ACCESS_KEY = "ldBA1dc++LxDE3m5yPRYQdIZPC33hV4UgBclNIfAA0yJ+76TBabx+Q=="; //AccessKey string obtained from Picovoice Console (https://picovoice.ai/console/)

static pv_picovoice_t *handle = NULL;

static int8_t memory_buffer[MEMORY_BUFFER_SIZE] __attribute__((aligned(16)));

static const float PORCUPINE_SENSITIVITY = 0.75f;
static const float RHINO_SENSITIVITY = 0.5f;

const uint8_t *keyword_array = KEYWORD_ARRAY;
const uint8_t *context_array = CONTEXT_ARRAY;

String personalIntentValue;

static void wake_word_callback(void) {
    //Serial.println("Wake word detected!");
    digitalWrite(LEDB, LOW);
}

static void inference_callback(pv_inference_t *inference) {
    //Serial.println("{");
    //Serial.print("    is_understood : ");
    personalIntentValue = inference->intent;
    //Serial.println(inference->is_understood ? "true" : "false");
    if (inference->is_understood) {
        //Serial.print("    intent : ");
        //Serial.println(personalIntentValue);
        if (inference->num_slots > 0) {
            //Serial.println("    slots : {");
            for (int32_t i = 0; i < inference->num_slots; i++) {
                //Serial.print("        ");
                //Serial.print(inference->slots[i]);
                //Serial.print(" : ");
                //Serial.println(inference->values[i]);
            }
            //Serial.println("    }");
        }
    }
    //Serial.println("}\n");
    pv_inference_delete(inference);
    personalIntent(personalIntentValue);
}

void setup() {
    Serial.begin(9600);
    //SerialUSB.begin(115200);
    while (!Serial);

    if (!APDS.begin()) {
    //Serial.println("Error initializing APDS9960 sensor!");
    }

      pinMode(LEDB, OUTPUT);
      pinMode(LEDG, OUTPUT);

    pv_status_t status = pv_audio_rec_init();
    if (status != PV_STATUS_SUCCESS) {
        //Serial.print("Audio init failed with ");
        //Serial.println(pv_status_to_string(status));
        while (1);
    }

    digitalWrite(LEDB, HIGH);
    digitalWrite(LEDG, HIGH);

    status = pv_picovoice_init(
        ACCESS_KEY,
        MEMORY_BUFFER_SIZE,
        memory_buffer,
        sizeof(KEYWORD_ARRAY),
        KEYWORD_ARRAY,
        PORCUPINE_SENSITIVITY,
        wake_word_callback,
        sizeof(CONTEXT_ARRAY),
        CONTEXT_ARRAY,
        RHINO_SENSITIVITY,
        1.0,
        true,
        inference_callback,
        &handle);
    if (status != PV_STATUS_SUCCESS) {
        //Serial.print("Holodeck init failed with ");
        //Serial.println(pv_status_to_string(status));
        while (1);
    }

    const char *rhino_context = NULL;
    status = pv_picovoice_context_info(handle, &rhino_context);
    if (status != PV_STATUS_SUCCESS) {
        //Serial.print("retrieving context info failed with");
        //Serial.println(pv_status_to_string(status));
        while (1);
    }
    //Serial.println("Wake word: Holodeck");
    //Serial.println(rhino_context);
}

void loop()
{
    const int16_t *buffer = pv_audio_rec_get_new_buffer();
    if (buffer) {
        const pv_status_t status = pv_picovoice_process(handle, buffer);
        if (status != PV_STATUS_SUCCESS) {
            //Serial.print("Holodeck process failed with ");
            //Serial.println(pv_status_to_string(status));
            while(1);
        }
    }

    if (APDS.gestureAvailable()) {
    // a gesture was detected, read and print to serial monitor
    gestureNext();
    int gesture = APDS.readGesture();
    switch (gesture) {
      default:
        break;
    }
  }
}
