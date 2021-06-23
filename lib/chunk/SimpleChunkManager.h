#ifndef EXT_NOISELIB_LIB_CHUNK_SIMPLECHUNKMANAGER_H_
#define EXT_NOISELIB_LIB_CHUNK_SIMPLECHUNKMANAGER_H_

#include <map>
#include <cstdint>
#include <lib/objects/MinecraftBlock.h>
#include <lib/chunk/Chunk.h>

class SimpleChunkManager {
 public:
  SimpleChunkManager(const int_fast16_t minHeight, const int_fast16_t maxHeight) : minY(minHeight), maxY(maxHeight) {}

  auto setChunk(int64_t chunkX, int64_t chunkZ, Chunk *chunk) -> void;
  auto getChunk(int64_t chunkX, int64_t chunkZ) -> Chunk *;

  auto getBlockAt(int_fast64_t x, int_fast16_t y, int_fast64_t z) -> MinecraftBlock;
  auto setBlockAt(int_fast64_t x, int_fast16_t y, int_fast64_t z, MinecraftBlock block) -> void;

  [[nodiscard]]  auto isInWorld(int_fast64_t x, int_fast16_t y, int_fast64_t z) const -> bool;

  [[nodiscard]] auto getMinY() const -> int_fast16_t;
  [[nodiscard]] auto getMaxY() const -> int_fast16_t;

  [[nodiscard]] auto getChunks() const -> std::map<uint_fast64_t, Chunk *>;

  auto destroyObjects() -> void;

 private:
  std::map<uint_fast64_t, Chunk *> chunks;

  int_fast16_t minY;
  int_fast16_t maxY;
};

#endif // EXT_NOISELIB_LIB_CHUNK_SIMPLECHUNKMANAGER_H_