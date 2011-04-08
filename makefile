OPT_FLAGS := -O0
all: converter
	g++ -c $(OPT_FLAGS) src/scene.cpp -o src/obj/scene.o
	g++ -c $(OPT_FLAGS) src/camera.cpp -o src/obj/camera.o
	g++ -c $(OPT_FLAGS) src/geometry.cpp -o src/obj/geometry.o
	g++ -c $(OPT_FLAGS) src/timer.cpp -o src/obj/timer.o
	g++ -c $(OPT_FLAGS) src/util.cpp -o src/obj/util.o
	g++ -c $(OPT_FLAGS) src/trianglemesh.cpp -o src/obj/trianglemesh.o		
	g++ src/test.cpp \
	    src/obj/camera.o \
	    src/obj/geometry.o \
	    src/obj/scene.o \
	    src/obj/timer.o \
	    src/obj/trianglemesh.o \
	    src/obj/util.o \
	    $(OPT_FLAGS) \
	    -lSDL -o test
converter:
	cd utils/obj_convert; $(MAKE)
clean:
	cd utils/obj_convert; $(MAKE) clean
	rm test
	rm src/obj/*.o
run: all
	./test test_scenes/cornell_box.scene
