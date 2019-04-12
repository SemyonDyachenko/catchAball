#include "Includes.h"

using namespace sf;
using std::cout;
using std::endl;


class MusicLoader {
private:
	Music music;
	std::string file;
	float volume;
public:
	MusicLoader(std::string file,float volume) {
		this->file = file;
		this->volume = volume;
		if (!music.openFromFile("../res/music/" + file + ".ogg")) {
			cout << "Error load music" << endl;
		}
		else {
			music.setVolume(volume);
			music.setLoop(true);
		}
	}
	/*void ResetVolume(float volume) {
		music.setVolume(volume);
	}*/

	void StartPlay() {
		music.play();
	}

	void StopPlay() {
		music.stop();
	}
};