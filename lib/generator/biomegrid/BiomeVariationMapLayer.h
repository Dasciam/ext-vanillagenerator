#ifndef EXT_NOISELIB_LIB_GENERATOR_BIOMEGRID_BIOMEVARIATIONMAPLAYER_H_
#define EXT_NOISELIB_LIB_GENERATOR_BIOMEGRID_BIOMEVARIATIONMAPLAYER_H_

#include <lib/pocketmine/BiomeList.h>
#include "MapLayer.h"

using namespace GridBiome;

class BiomeVariationMapLayer : public MapLayer {

 public:
  BiomeVariationMapLayer(int_fast64_t seed, MapLayer &belowLayer, MapLayer *variationLayer)
      : MapLayer(seed), below_layer_(belowLayer), variation_layer_(variationLayer) {}

  BlockValues GenerateValues(int x, int z, int size_x, int size_z) override;

 private:
  /**
   * Generates a rectangle, replacing all the positive values in the previous layer with random
   * values from 2 to 31 while leaving zero and negative values unchanged.
   *
   * @param x the lowest x coordinate
   * @param z the lowest z coordinate
   * @param size_x the x coordinate range
   * @param size_z the z coordinate range
   * @return a flattened array of generated values
   */
  BlockValues GenerateRandomValues(int x, int z, int size_x, int size_z);

  /**
   * Generates a rectangle using the previous layer and the variation layer.
   *
   * @param x the lowest x coordinate
   * @param z the lowest z coordinate
   * @param size_x the x coordinate range
   * @param size_z the z coordinate range
   * @return a flattened array of generated values
   */
  BlockValues MergeValues(int x, int z, int size_x, int size_z);

  MapLayer &below_layer_;
  MapLayer *variation_layer_;
  const std::vector<int> islands_ = {PLAINS, FOREST};
  const std::map<int, std::vector<int>> variations_ = {
      {DESERT, {DESERT_HILLS}},
      {FOREST, {FOREST_HILLS}},
      {BIRCH_FOREST, {BIRCH_FOREST_HILLS}},
      {ROOFED_FOREST, {PLAINS}},
      {TAIGA, {TAIGA_HILLS}},
      {MEGA_TAIGA, {MEGA_TAIGA_HILLS}},
      {COLD_TAIGA, {COLD_TAIGA_HILLS}},
      {PLAINS, {FOREST, FOREST, FOREST_HILLS}},
      {ICE_PLAINS, {ICE_MOUNTAINS}},
      {JUNGLE, {JUNGLE_HILLS}},
      {OCEAN, {DEEP_OCEAN}},
      {EXTREME_HILLS, {EXTREME_HILLS_PLUS}},
      {SAVANNA, {SAVANNA_PLATEAU}},
      {MESA_PLATEAU_FOREST, {MESA}},
      {MESA_PLATEAU, {MESA}},
      {MESA, {MESA}}
  };
};

#endif //EXT_NOISELIB_LIB_GENERATOR_BIOMEGRID_BIOMEVARIATIONMAPLAYER_H_
