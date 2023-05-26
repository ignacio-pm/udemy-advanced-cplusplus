#include <iostream>
using namespace std;

// Parent classes need virtual methods if the child need to override them

class MusicalInstrument {
public:
  MusicalInstrument() { cout << "Creating instrument ..." << endl; }
	virtual void play(){ cout << "Playing instrument ..." << endl; }
	virtual void reset(){ cout << "Resetting instrument ..." << endl; }
	virtual ~MusicalInstrument(){ cout << "Deleting instrument ..." << endl; };
};

class Machine {
public:
  Machine() { cout << "Creating machine ..." << endl; }
	virtual void start(){ cout << "Starting machine ..." << endl; }
	virtual void reset(){ cout << "Resetting machine ..." << endl; }
	virtual ~Machine(){ cout << "Deleting machine ..." << endl; };
};

// A class can inherit properties from multiple classes. However, it should be checked for methods
// or objects with identical signatures
class Synthesizer: public Machine, public MusicalInstrument {
public:
  // The parents' destructors run on top of the virtual destructor of the child
	virtual ~Synthesizer(){};
};

int main() {

	Synthesizer *pSynth = new Synthesizer();

	// Methods of both parent classes can be called
  pSynth->start();
	pSynth->play();
  // The main problem of multiple inheritance is that there could be methods with identical
  // signatures in both parent classes. To use these methods, the user has to define from which
  // parent should the method be used, since pSynth->reset(); causes compilation error.
  // This does not happen with constructors or destructors. The parent constructors are always used.
  
  // Then, the details of the child class implementation cannot be encapsulated since the user needs
  // to know which parent's method is the best for its use. This causes the exposure of the parent
  // class implementation
	pSynth->Machine::reset();
	pSynth->MusicalInstrument::reset();

  // A possible solution would be to override the virtual method in the child class
	// virtual void reset(){ cout << "Resetting synthesizer..." << endl; }

	delete pSynth;
	return 0;
}