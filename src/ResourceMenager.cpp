#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/TextureMenager.hpp"

template <class Resource>
ResourceMenager<Resource>::~ResourceMenager()
{
    //Cleanup memory
    Resources.clear();
    dirs.clear();
}


template <class Resource>
const std::shared_ptr<Resource> ResourceMenager<Resource>::get( const std::string& filename )
{
	// Check, whether the Resource already exists
	for( typename std::map<std::string, std::shared_ptr<Resource>>::const_iterator it = Resources.begin(); it != Resources.end(); ++it)
	{
		if( filename == it->first )
		{
			std::cout << "DEBUG_MESSAGE: " << filename << " using existing image.\n";
			return it->second;
		}
	}
	
	// The Resource doesen't exists. Create it and save it.
    std::shared_ptr<Resource> newResource = std::make_shared<Resource>();

	// Search project's main directory
	if( newResource.get()->loadFromFile( filename ) )
	{
		Resources[filename] = newResource;
		std::cout << "DEBUG_MESSAGE: " << filename << " loading image.\n";
		return Resources[filename];
	}

	// If the Resource has still not been found, search all registered directories
	for( typename std::vector< std::string >::iterator it = dirs.begin(); it != dirs.end(); ++it )
	{
		if( newResource.get()->loadFromFile( (*it) + filename ) )
		{
			Resources[filename] = newResource;
			std::cout << "DEBUG_MESSAGE: " << filename << " loading image.\n";
			return Resources[filename];
		}

	}

	std::cout << "GAME_ERROR: Image was not found. It is filled with an empty image.\n";
	Resources[filename] = newResource;
	return Resources[filename];
}

template <class Resource>
void ResourceMenager<Resource>::deleteResource( const std::shared_ptr<Resource>& resource )
{
	for( typename std::map<std::string, std::shared_ptr<Resource>>::const_iterator it = Resources.begin(); it != Resources.end(); ++it)
	{
		if( resource == it->second )
		{
			Resources.erase( it );
            return;
		}
	}
}

template <class Resource>
void ResourceMenager<Resource>::deleteResource( const std::string& filename )
{
	typename std::map<std::string, std::shared_ptr<Resource>>::const_iterator it = Resources.find( filename );
	if( it != Resources.end() )
		Resources.erase( it );
}

template <class Resource>
void ResourceMenager<Resource>::addDir( const std::string& directory )
{
	// Check whether the path already exists
	for( typename std::vector<std::string>::const_iterator it  = dirs.begin(); it != dirs.end(); ++it )
	{
		// The path exists. So it isn't necessary to add id once more.
		if( directory == (*it) )
			return;
	}

	// insert the directory
	dirs.push_back( directory );
}

template <class Resource>
void ResourceMenager<Resource>::removeDir( const std::string& directory )
{
	for( typename std::vector<std::string>::iterator it  = dirs.begin(); it != dirs.end(); )
	{
		if( directory == (*it) )
			it = dirs.erase( it );
		else
			++it;
	}
}

template class ResourceMenager<sf::Texture>;
template class ResourceMenager<sf::Font>;