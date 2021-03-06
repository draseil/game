#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <tmx.h>
#include "entity.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

#define WORLD_COLOR_HARD { 0, 255, 0 }

SDL_Rect camera;

SDL_Texture *buffer;
SDL_Texture *collision_buffer;
SDL_Texture *map_collision_buffer;

// 0 success value, negative on error
int buffers_init(SDL_Renderer *ren);

void setColor(SDL_Renderer*, int color);

void renderClear(SDL_Renderer*);
void render(SDL_Renderer*, SDL_Texture*, SDL_Rect*, SDL_Rect*, int color[3]);
void renderEntity(SDL_Renderer*, entity*, int color[3]);
void renderToBuffer(SDL_Renderer*, SDL_Texture*, SDL_Rect*, SDL_Rect*);
void renderToCollisionBuffer(SDL_Renderer*, SDL_Rect*, SDL_Rect*, int color[3]);

SDL_Texture* fillRect(SDL_Renderer *ren, SDL_Rect *rect, int color[3]);

// Camera stuff (It's messy, sorry)
SDL_Rect createCamera();
void setCameraToEntity(SDL_Rect camera, entity * e);

// If occours any errors, prints to stderr
void setTargetToCollisionBuffer(SDL_Renderer*);
void setTargetToBuffer(SDL_Renderer*);

SDL_Texture* renderMap(SDL_Renderer*, tmx_map*);

void drawObjects(SDL_Renderer*, tmx_object*, int);
void drawPolyline(SDL_Renderer *ren, int **points, int x, int y, int pointsc);
void drawPolygon(SDL_Renderer *ren, int **points, int x, int y, int pointsc);
void drawLayer(SDL_Renderer *ren, SDL_Texture *res, tmx_map *map, tmx_layer *layer);
void drawImageLayer(SDL_Renderer *ren, tmx_image *img);

void updateCamera();

#endif  // RENDER_H
