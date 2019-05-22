#ifndef TEXTURE_MENAGER_H
#define TEXTURE_MENAGER_H

#include <SFML/Graphics.hpp>
#include <memory>

class TextureMenager{
    public:
        ~TextureMenager();

        const std::shared_ptr<sf::Texture> get( const std::string& filename );
        void deleteTexture(const std::shared_ptr<sf::Texture>&);
        void deleteTexture( const std::string& filename );
        void addDir(const std::string& dir);
        void removeDir( const std::string& directory );



    private:
        std::map< std::string, std::shared_ptr<sf::Texture> > textures;
        std::vector< std::string > dirs;
};
#endif