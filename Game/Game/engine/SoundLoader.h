#include "Includes.h"

using namespace sf;
using std::cout;
using std::endl;

class SoundLoader {
private:
	SoundBuffer buffer;
	std::string filename;
	float volume;
public:
	Sound sound;
	SoundLoader(std::string filename,float volume) {
		this->filename = filename;
		this->volume = volume;
		if (buffer.loadFromFile("../res/music/" + filename + ".ogg")) {
			sound.setBuffer(buffer);
			sound.setVolume(volume);
		}
		else {
			cout << "Error load sound buffer" << endl;
		}
	}

		void SetLoop(bool value) {
			sound.setLoop(value);
		}

		void SetStart() {
			sound.play();
		}

		void SetStop() {
			sound.stop();
		}
};