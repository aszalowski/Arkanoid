#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/TextureMenager.hpp"


TextureMenager::~TextureMenager()
{
    //Cleanup memory
    textures.clear();
    dirs.clear();
}


const std::shared_ptr<sf::Texture> TextureMenager::get( const std::string& filename )
{
	// Check, whether the texture already exists
	for( std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it = textures.begin(); it != textures.end(); ++it)
	{
		if( filename == it->first )
		{
			std::cout << "DEBUG_MESSAGE: " << filename << " using existing image.\n";
			return it->second;
		}
	}
	
	// The texture doesen't exists. Create it and save it.
    std::shared_ptr<sf::Texture> newTexture = std::make_shared<sf::Texture>();

	// Search project's main directory
	if( newTexture.get()->loadFromFile( filename ) )
	{
		textures[filename] = newTexture;
		std::cout << "DEBUG_MESSAGE: " << filename << " loading image.\n";
		return textures[filename];
	}

	// If the texture has still not been found, search all registered directories
	for( std::vector< std::string >::iterator it = dirs.begin(); it != dirs.end(); ++it )
	{
		if( newTexture.get()->loadFromFile( (*it) + filename ) )
		{
			textures[filename] = newTexture;
			std::cout << "DEBUG_MESSAGE: " << filename << " loading image.\n";
			return textures[filename];
		}

	}

	std::cout << "GAME_ERROR: Image was not found. It is filled with an empty image.\n";
	textures[filename] = newTexture;
	return textures[filename];
}

void TextureMenager::deleteTexture( const std::shared_ptr<sf::Texture>& texture )
{
	for( std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it = textures.begin(); it != textures.end(); ++it)
	{
		if( texture == it->second )
		{
			textures.erase( it );
            return;
		}
	}
}

void TextureMenager::deleteTexture( const std::string& filename )
{
	std::map<std::string, std::shared_ptr<sf::Texture>>::const_iterator it = textures.find( filename );
	if( it != textures.end() )
		textures.erase( it );
}

void TextureMenager::addDir( const std::string& directory )
{
	// Check whether the path already exists
	for( std::vector<std::string>::const_iterator it  = dirs.begin(); it != dirs.end(); ++it )
	{
		// The path exists. So it isn't necessary to add id once more.
		if( directory == (*it) )
			return;
	}

	// insert the directory
	dirs.push_back( directory );
}

void TextureMenager::removeDir( const std::string& directory )
{
	for( std::vector<std::string>::iterator it  = dirs.begin(); it != dirs.end(); )
	{
		if( directory == (*it) )
			it = dirs.erase( it );
		else
			++it;
	}
}