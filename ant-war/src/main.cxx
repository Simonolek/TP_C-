



#pragma once 

#ifdef _WIN32
#include <SDL.h>

#define not !

#else

#include <SDL2/SDL.h>

#endif

#include <iostream>
#include <random>
#include <vector>
#include <cmath>
 
#include "it_s_work.h"
#include "../utilities.h"
#include "../boid.h"
#include "../physics.h"






int const WIDTH = 800;
int const HEIGHT = 600;
float const PI = 3.1415927; // TODO: better PI

struct global_t {
	SDL_Window * window = NULL;
	SDL_Renderer * renderer = NULL;

	// random
	std::random_device rd;
	std::default_random_engine eng;
	std::uniform_real_distribution<float> rand;

};

global_t g;

void paint_it_s_work(int ox, int oy, int scale = 20) {
	SDL_SetRenderDrawColor(g.renderer, 0u, 0u, 0u, SDL_ALPHA_OPAQUE);
	for (int j = 0; j < px::height; ++j) {
		for (int i = 0; i < px::width; ++i) {
			if (px::header_data[j*px::width+i] == 0) {
				SDL_Rect r = { i*scale+ox, j*scale+oy, 20, 20 };
				SDL_RenderFillRect(g.renderer, &r);
			}
		}
	}
}

void paint_boids(boids boidz, int ox, int oy, int scale = 20) {
	SDL_SetRenderDrawColor(g.renderer, 0u, 0u, 0u, SDL_ALPHA_OPAQUE);
	for (int i = 0; i < boidz.nombre; i++) {
		std::cout << boidz.vec[i].pos.x << " " << boidz.vec[i].pos.y << std::endl;
		SDL_Rect r = {boidz.vec[i].pos.x + ox, boidz.vec[i].pos.y + oy, 10, 10};
			SDL_RenderFillRect(g.renderer, &r);
	}
	std::cout << "FIN DE LA LIGNE" << std::endl;

}

void do_render(boids boidz) {
	SDL_SetRenderDrawColor(g.renderer, 255u, 255u, 255u, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(g.renderer);

	paint_boids(boidz, 0, 0, 20);

	SDL_RenderPresent(g.renderer);
}

void do_update(boids& boidz) {
	boidz = next_boids(boidz);

}

int main(int argc, char** argv) {

	boids boidz(20);

	int status;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_TIMER) != 0) { // on initialise et
		return 1;																			// on verifie que ca
	}																						// c'est bien passé

	g.window = SDL_CreateWindow("Boids",						// on crée la fenêtre 
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (not g.window) {
		return 1;
	}

	// get the default renderer
	g.renderer = SDL_CreateRenderer(g.window, -1, 0);
	if (not g.renderer) {
		return 1;
	}

	bool end = false;
	while (not end) {
		SDL_Event event;
		if (SDL_WaitEventTimeout(&event, 20)) {
			switch (event.type) {
			case SDL_WINDOWEVENT:
				switch (event.window.event) {
					case SDL_WINDOWEVENT_CLOSE:
						end = true;
						break;
					case SDL_WINDOWEVENT_SIZE_CHANGED:
						// Should never happen
						break;
					default:
						break;
				}
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					end = true;
				}
				break;
			case SDL_KEYUP:
				break;
			}
		} else {
			// Got time out or error
			char const * e = SDL_GetError();
			if (e != NULL) {
				if (strlen(e) != 0) {
					// Got error
					return 1;
				}
			}

			do_update(boidz);
			do_render(boidz);
		}
	}

	SDL_DestroyRenderer(g.renderer);
	SDL_DestroyWindow(g.window);
	SDL_CloseAudio();
	SDL_Quit();
	return 0;
}

/*

#include <iostream>
#include <random>
#include <vector>
#include <cmath>

#include "../utilities.h"
#include "../boid.h"
#include "../physics.h"



int main() {

	srand(time(NULL));

	boids boidz(200);

	std::cout << boidz.nombre << std::endl;
	
	
	for (int i = 0; i < boidz.nombre; i++) {
		std::cout << boidz.vec[i].pos.x << " " << boidz.vec[i].pos.y << std::endl;
	};
	return 0;
	
	

}

*/

