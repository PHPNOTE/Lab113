#include <iostream>
#include <string>
using namespace std;

class MusicPlaylist{
private:
    string song[20];
    int allSong = 0;
    int currentTrack;
public:
    void add(string songname){
        song[allSong] = songname;
        allSong += 1;
    }
    void setCurrentTrack(int numSong){
        currentTrack = numSong;
    }
    string play(){
        return song[currentTrack - 1];
    }
};


int main()
{
    MusicPlaylist mp;
    mp.add("Shape of You");
    mp.add("That's What I Like");
    mp.add("Humble");
    mp.setCurrentTrack(1);
    cout << mp.play() << endl; // แสดงเพลงลำดับที่ 1 คือ Shape of You
}