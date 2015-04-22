#include "entity.h"
#include "game.h"

entity* CreateEntity(SDL_Renderer *ren, int x, int y, char *imagePath) {
    SDL_Surface *img = SDL_LoadBMP(imagePath);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, img);
    SDL_FreeSurface(img);

    entity *e = malloc(sizeof(entity));
    e->x = x;
    e->y = y;
    e->x_vel = 0;
    e->y_vel = 0;
    e->velocity = 50;
    e->curr_img = tex;
    e->type = ENTITY_TYPE_DEFAULT;
    return e;
}

void rendererEntity(SDL_Renderer *ren, entity *e) {
    SDL_Rect dst;
    dst.x = e->x;
    dst.y = e->y;
    SDL_QueryTexture(e->curr_img, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(ren, e->curr_img, NULL, &dst);
}

void updateEntity(entity *e, float deltaTimeS) {
    switch (e->type) {
        case ENTITY_TYPE_DEFAULT:
            if (character->x < e->x) e->x -= e->velocity * deltaTimeS;
            if (character->x > e->x) e->x += e->velocity * deltaTimeS;
            if (character->y < e->y) e->y -= e->velocity * deltaTimeS;
            if (character->y > e->y) e->y += e->velocity * deltaTimeS;
            break;
        case ENTITY_TYPE_MAIN_CHARACTER:
            e->x += e->x_vel;
            e->y += e->y_vel;
            break;
        case ENTITY_TYPE_PET:
            if (character->x - 25 < e->x) e->x -= e->velocity * deltaTimeS;
            if (character->x + 25 > e->x) e->x += e->velocity * deltaTimeS;
            if (character->y - 25 < e->y) e->y -= e->velocity * deltaTimeS;
            if (character->y + 25 > e->y) e->y += e->velocity * deltaTimeS;
            break;
        default:
            printf("Invalid entity type");
            break;
    }
}

void eventEntity(entity * e, SDL_Event event, float deltaTimeS) {
    if (event.type == SDL_KEYDOWN) {
        SDL_Scancode key = event.key.keysym.scancode;
        if (key == SDL_SCANCODE_A) {
            entity_move_left(e, deltaTimeS);
        } else if (key == SDL_SCANCODE_D) {
            entity_move_right(e, deltaTimeS);
        } else if (key == SDL_SCANCODE_S) {
            entity_move_down(e, deltaTimeS);
        } else if (key == SDL_SCANCODE_W) {
            entity_move_up(e, deltaTimeS);
        }
    } else if(event.type == SDL_KEYUP) {
        SDL_Scancode key = event.key.keysym.scancode;
        if (key == SDL_SCANCODE_A || key == SDL_SCANCODE_D) {
            character->x_vel = 0;
        } else if (key == SDL_SCANCODE_S || key == SDL_SCANCODE_W) {
            character->y_vel = 0;
        }
    }
}

void entity_move_left(entity *e, float deltaTimeS) {
    e->x_vel -= e->velocity * deltaTimeS * 5 + e->x_vel;
}

void entity_move_right(entity *e, float deltaTimeS) {
    e->x_vel += e->velocity * deltaTimeS * 5 - e->x_vel;
}
void entity_move_up(entity *e, float deltaTimeS) {
    e->y_vel -= e->velocity * deltaTimeS * 5 + e->y_vel;
}

void entity_move_down(entity *e, float deltaTimeS) {
    e->y_vel += e->velocity * deltaTimeS * 5 - e->y_vel;
}