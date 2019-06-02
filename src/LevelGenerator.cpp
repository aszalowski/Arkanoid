#include "../include/LevelGenerator.hpp"

#define createBlock(hp) Block a((hp), texture, sf::Vector2f(99 + j * 34, 117 + i * 18)); game->blocks.push_back(a);

void generateLevel(GameEngine *game)
{
    const std::shared_ptr<sf::Texture> texture = game->textureMenager.get("breakout_pieces.png");
    srand(time(nullptr));
    for (int i = 0; i < 7; ++i)
    {
        bool rowExist = rand() % 2;
        if (rowExist)
        {
            bool solid = rand() % 2;
            bool alternatingColors = rand() % 2;
            //std::cout << "Row " << i << " solid " << solid << " alternating colors " << alternatingColors << std::endl;
            if (solid)
            {
                if (alternatingColors)
                {
                    uint hp1 = rand() % 5 + 1;
                    uint hp2 = rand() % 5 + 1;
                    for (int j = 0; j < 13; j++)
                    {
                        if (j % 2)
                        {
                            createBlock(hp1);
                        }
                        else
                        {
                            createBlock(hp2);
                        }
                    }
                }
                else
                {
                    uint hp1 = rand() % 5 + 1;
                    for (int j = 0; j < 13; j++)
                    {
                        createBlock(hp1);
                    }
                }
            }
            else
            {
                bool beginning = rand() % 2;
                if (alternatingColors)
                {
                    uint hp1 = rand() % 5 + 1;
                    uint hp2 = rand() % 5 + 1;
                    int counter = 0;
                    for (int j = beginning; j < 13; j += 2)
                    {
                        if (counter % 2 == 0)
                        {
                            createBlock(hp1);
                        }
                        else
                        {
                            createBlock(hp2);
                        }
                        counter++;
                    }
                }
                else
                {
                    uint hp1 = rand() % 5 + 1;
                    for (int j = 0; j < 13; j++)
                    {
                        createBlock(hp1);
                    }
                }
            }
        }
    }
}