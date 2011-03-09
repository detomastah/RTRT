all: converter
	gcc -c src/scene.c -o src/obj/scene.o
	gcc -c src/camera.c -o src/obj/camera.o
	gcc -c src/face.c -o src/obj/face.o
	gcc -c src/vector.c -o src/obj/vector.o
	gcc src/test.c \
	    src/obj/face.o \
	    src/obj/camera.o \
	    src/obj/vector.o \
	    src/obj/scene.o \
	    -lSDL -o test
converter:
	cd utils/obj_convert; $(MAKE)
clean:
	cd utils/obj_convert; $(MAKE) clean
	rm test
	rm src/obj/*.o
run: all
	./test test_scenes/cornell_box.scene
