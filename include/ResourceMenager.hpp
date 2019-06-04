#ifndef RESOURCE_MENAGER_H
#define RESOURCE_MENAGER_H

#include <SFML/Graphics.hpp>
#include <memory>
///Manager for textures and fonts
template <class Resource>
class ResourceMenager
{
public:
    ~ResourceMenager();

    const std::shared_ptr<Resource> get(const std::string &filename); ///< Checks if resource wasn't used before, kooks for the file in the directory, creates a shared pointed and returns it, if the resource was used returns it's shared pointer
    void deleteResource(const std::shared_ptr<Resource> &);           ///< Deletes resource
    void deleteResource(const std::string &filename);                 ///< Deletes resource
    void addDir(const std::string &dir);                              ///< Adds a directory, where looks for resources
    void removeDir(const std::string &directory);                     ///< Removes a directory

private:
    std::map<std::string, std::shared_ptr<Resource>> Resources; ///< Stores pointers of resources
    std::vector<std::string> dirs;                              ///< Stores names of the used directories
};
#endif