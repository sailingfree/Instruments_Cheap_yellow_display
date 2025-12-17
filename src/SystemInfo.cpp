/* CHIPTEST 1.0 by ullix
 * choose any license you want
 * */

#include <Arduino.h>
#include <esp_partition.h>

size_t total = 0;
void partloop(esp_partition_type_t part_type, Stream & stream) {

  esp_partition_iterator_t iterator = NULL;
  const esp_partition_t *next_partition = NULL;
  iterator = esp_partition_find(part_type, ESP_PARTITION_SUBTYPE_ANY, NULL);

  while (iterator) {
     next_partition = esp_partition_get(iterator);
     if (next_partition != NULL) {
        stream.printf("   partition addr: 0x%06x; size: 0x%06x (%d Bytes); label: %s\n", 
                next_partition->address, next_partition->size, next_partition->size/(1), next_partition->label);
        total += next_partition->size;
     iterator = esp_partition_next(iterator);
    }
  }
  stream.printf("Total flash size = %d\n", total);
}


void ESPinfo(Stream & stream){

    stream.println("\nChip Info -----------------------------------------------");

    float ESPSketchPercMax  = 100.0f * ESP.getSketchSize() / ESP.getFreeSketchSpace(); // Sketch size in percent of maxpossible sketch size

    // code
    stream.printf("   SketchSize:     %i (0x%X) (%0.2f%% of Max)\n",    ESP.getSketchSize(), ESP.getSketchSize(), ESPSketchPercMax);
    stream.printf("   MaxSketchSpace: %i (0x%X)\n",                     ESP.getFreeSketchSpace(), ESP.getFreeSketchSpace());
    stream.printf("   SketchMD5:      %s\n\n",                          ESP.getSketchMD5().c_str());
    stream.printf("   SdkVersion:     %s\n\n",                          ESP.getSdkVersion());


    // Flash
    stream.printf("   FlashChipSize:  %i    (0x%X)\n",                  ESP.getFlashChipSize(), ESP.getFlashChipSize());
    stream.printf("   FlashChipSpeed: %i\n",                            ESP.getFlashChipSpeed());
    stream.printf("   FlashChipMode:  %i \n\n",                         ESP.getFlashChipMode());

    // chip stuff
    stream.printf("   ChipID:         %llu  (0x%llX)  (64bit!)\n",        ESP.getEfuseMac(), ESP.getEfuseMac());     // 64 bit result
    stream.printf("   ChipModel:      %s\n",                            ESP.getChipModel());
    stream.printf("   ChipCores:      %-7i\n",                          ESP.getChipCores());
    stream.printf("   ChipRevision:   %i\n",                            ESP.getChipRevision());
    stream.printf("   CpuFreqMHz:     %i\n",                            ESP.getCpuFreqMHz());
    stream.printf("   CycleCount:     %u\n\n",                          ESP.getCycleCount());

    //Internal RAM
    stream.printf("   HeapSize:       %-7i  (0x%X)\n",                  ESP.getHeapSize(),      ESP.getHeapSize());
    stream.printf("   FreeHeap:       %-7i  (0x%X)\n",                  ESP.getFreeHeap(),      ESP.getFreeHeap());
    stream.printf("   MinFreeHeap:    %-7i  (0x%X)\n",                  ESP.getMinFreeHeap(),   ESP.getMinFreeHeap());
    stream.printf("   MaxAllocHeap:   %-7i  (0x%X)\n\n",                ESP.getMaxAllocHeap(),  ESP.getMaxAllocHeap());

    // PSRAM
    stream.printf("   PSRAMSize:       %-7i  (0x%X)\n",                  ESP.getPsramSize(),      ESP.getPsramSize());
    stream.printf("   FreePSRAM:       %-7i  (0x%X)\n",                  ESP.getFreePsram(),      ESP.getFreePsram());
    stream.printf("   MinFreePSRAM:    %-7i  (0x%x)\n",                  ESP.getMinFreePsram(),      ESP.getMinFreePsram());
    stream.printf("   MaxAllocPSRAM:   %-7i  (0x%X)\n",                  ESP.getMaxAllocPsram(),      ESP.getMaxAllocPsram());
}


void systemInfo(Stream & stream){
    stream.println("\n### CHIPTEST 1.0 ##########################################");

    stream.println("\nPartition list:");
    partloop(ESP_PARTITION_TYPE_APP, stream);
    partloop(ESP_PARTITION_TYPE_DATA, stream);

    ESPinfo(stream);
}