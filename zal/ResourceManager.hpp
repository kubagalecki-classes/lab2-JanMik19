#pragma once
#include "Resource.hpp"

class ResourceManager
{
    Resource* wsk; // wskaznik na strukture Resource
public:
    ResourceManager(); // konstruktor
    ResourceManager(const ResourceManager&); // konstruktor kopiujacy
    ResouceManager(ResouceManager&&); // kontruktor przenoszacy
    double get(); // metoda get()
    ~ResourceManager(); // destruktor
    ResourceManager& operator=(const ResourceManager&); // kopiujacy operator przepisania
    ResourceManager& operator=(ResouceManager&&); // przenoszacy operator przypisania
};

ResourceManager::ResourceManager()
{
    wsk = new Resource;
}

ResourceManager::ResourceManaget(const ResourceManager& obj)
{
    wsk = new Resource;
    *wsk = *obj.wsk;
}

ResouceManager::~ResourceManager()
{
    delete wsk;   
}

double ResourceManager::get()
{  
    return wsk->get();  
}

ResourceManager& ResourceManager::operator=(const ResourceManager& obj)
{
    if(this != &obj)
    {
        //cout << "assing\n;
        *wsk = *obj.wsk;
    }
    return *this;
}

ResouceManager::ResouceManager(ResouceManager&& obj1)
{
  wsk = obj1.wsk;
  obj1.wsk = nullptr;
}

ResouceManager& ResouceManager::operator=(ResouceManager&& obj1)
{
  if (this != &obj1)
  {
    delete wsk;
    wsk = obj1.wsk;
    obj1.wsk = nullptr;
  }
  return *this;
}
