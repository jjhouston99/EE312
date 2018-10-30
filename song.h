#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Song{
private:
    string name;
    string artist;
    int datasize;

public:
    Song();
    Song(string artist, string name, int size);

    string get_artist()const {return artist;}
    string get_name()const {return name; }
    int get_size()const {return datasize; }

    void set_artist(string artist){this->artist = artist;}
    void set_name(string name){this->name = name;}
    void set_size(int size){this->datasize = size;}
};

