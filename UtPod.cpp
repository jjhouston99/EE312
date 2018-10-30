#include "UtPod.h"
#include <cstdlib>
#include <iostream>

UtPod::UtPod(){
    UtPod::memSize = MAX_MEMORY;
    UtPod::songs = nullptr;
}

 UtPod::UtPod(int size) {
     UtPod::memSize = size;
     UtPod::songs = nullptr;
 }

int UtPod::addSong(Song const &s){
    if(s.get_size() <= getRemainingMemory()){ //change later to traverse linked list to find memory used

        SongNode *temp = new SongNode;
        temp->s = s;
        if(songs == NULL) {
            temp->next = NULL;
            songs = temp;
        }
        else{
            temp->next = songs;
            songs = temp;
        }
        return SUCCESS;
    }
    else return NO_MEMORY;
}

int UtPod::removeSong(Song const &s){

    if(songs == nullptr){ return 1; } // song list is empty

    SongNode *(temp) = songs;
    SongNode *(prev_temp) = nullptr; // to save previous node in list


    while(temp != nullptr ){  // list has not traversed
                    //for name                                              //for artist
        if((temp->s.get_name() == s.get_name())   &&    (temp->s.get_artist() == s.get_artist())){

            if(prev_temp == nullptr){ // in case the song is the first element in the linked list
               songs = temp->next; // change the head to the next element in the list

               delete temp;
            }else {

                prev_temp->next = temp->next; // skip over the song on the linked list, "deleting it"
                delete temp;
            }


            return 0;
        }

        prev_temp = temp;
        temp = temp->next;
    }

    //if we didn't find a matching song return that we were unsuccessful
    return 1;
}

void UtPod::shuffle(){
// use computer time for seed
}

void UtPod::showSongList(){
    using namespace std;
    SongNode *p = songs;
    while(p != NULL){
        cout << p->s.get_name() << ", " << p->s.get_artist() << ", " << p->s.get_size()  << endl;
p = p->next;
}
}

void UtPod::sortSongList(){
    if(songs == NULL){
        return;
    }
    SongNode *p = songs;
    SongNode *p2;
    while(p!=NULL){
        p2 = p->next;
        while(p2!=NULL){
            if(p2->s.get_name() < p->s.get_name()){
                string temp = p2->s.get_name();
                p2->s.set_name(p->s.get_name());
                p->s.set_name(temp);

                temp = p2->s.get_artist();
                p2->s.set_artist(p->s.get_artist());
                p->s.set_artist(temp);

                int tempSize = p2->s.get_size();
                p2->s.set_size(p->s.get_size());
                p->s.set_size(tempSize);
            }
            p2 = p2->next;
        }
        p = p->next;
    }
    }


void UtPod::clearMemory(){

}

int UtPod::getRemainingMemory(){

}

UtPod::~UtPod(){

}
