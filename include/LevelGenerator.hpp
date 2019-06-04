#include "../include/GameEngine.hpp"
#include <ctime>
/// Procedural level generation
namespace LevelGenerator
{
void generateLevel(GameEngine *); ///< Randomizes if row is empty, is it solid or skips every second block, one or two colors
}