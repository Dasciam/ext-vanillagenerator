#include "NoiseMapLayer.h"

BlockValues NoiseMapLayer::GenerateValues(int x, int z, int size_x, int size_z) {
  BlockValues values;
  for (int i = 0; i < size_z; ++i) {
    for (int j = 0; j < size_x; ++j) {
      double noise = noise_gen_->noise(x + j, z + i, 0.175, 0.8, true) * 4.0;
      int val;
      if (noise >= 0.05) {
        val = noise <= 0.2 ? 3 : 2;
      } else {
        SetCoordsSeed(x + j, z + i);

        val = NextInt(2) == 0 ? 3 : 0;
      }

      values.insert({j + i * size_x, val});
    }
  }

  return values;
}
