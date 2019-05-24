#ifndef RESOURCE_MENAGER_H
#define RESOURCE_MENAGER_H

#include <SFML/Graphics.hpp>
#include <memory>

template<class Resource>
class ResourceMenager{
    public:
        ~ResourceMenager();

        const std::shared_ptr<Resource> get( const std::string& filename );
        void deleteResource(const std::shared_ptr<Resource>&);
        void deleteResource( const std::string& filename );
        void addDir(const std::string& dir);
        void removeDir( const std::string& directory );



    private:
        std::map< std::string, std::shared_ptr<Resource> > Resources;
        std::vector< std::string > dirs;
};
#endif