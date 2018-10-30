#include "song.h"
#include <cstdlib>
#include <iostream>
#include <string>


Song::Song() {
    Song::name = "";
    Song::artist = "";
    Song::datasize = 0;

}

Song::Song(string artist, string name, int size) {
    this->artist = artist;
    this->name = name;
    this->datasize = size;
}

