# Brooklyn Scintillating Fibres Hodoscope
A Geant4 simulation of a 16-plane hodoscope of scintillating fibres with different sizes, hit by muons at MIP with an angle of 40 degree wrt the surface.

The geometry of the detector is inspired to Brooklyn, a scintillating fibres hodoscope in the Marconi Building Educational Laboratory of the Sapienza University's Physics Department.

The detector is a 16mmx17.6mmx20cm parallelepiped made by 16 planes of polystyrene scintillating fibres (scintillation was not implemented). Up and down the fibres a mylar sheet was placed, and between the fibres there ara some plystyrene supports.
The fibres are squared, except for the ones in channel 2,3,12,13, that are circular. The sizes (side for the squared ones and diameter for the circulare ones) of the fibres are, for channel 0 to 15 : (1mm, 1mm, 0.5mm, 0.5mm, 0.25mm, 0.25mm, 0.2mm, 0.2mm, 0.2mm, 0.25mm, 0.25mm, 0.25mm, 0.5mm, 0.5mm, 1mm, 1mm) 

The muons are randomly shot with G4ParticleGun at a 40 degree angle with the surface, and at a 350MeV momentum (MIP for muons).

The simulation gives in output a file called stuff.txt where you can read the energy released on a fibre step by step. Cleaner.cpp, a c++ program in the cleaner+pythonDataAnalysis folder, can read this output file and give another file with the energy released on the 16 channels event by event. In the same folder you can find a small python notebook written for the data analysis.

Credits : Francesco Artibani (mail : artibani.1727820@studenti.uniroma1.it), Francesco Clozza (mail : clozza.1792595@studenti.uniroma1.it)
