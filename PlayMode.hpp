#include "PPU466.hpp"
#include "Mode.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>
#include <set>

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} left, right, down, up;


	float dead = 0.0f;
    int score = 0;
    int best_score = 0;
    float time = 20.0f;

    std::set<std::pair<int32_t, int32_t>> fire;

	//player position:
	glm::vec2 player_at = glm::vec2(0.0f);

	std::set<std::pair<int32_t, int32_t>> trails = {{0,0}};

	//----- drawing handled by PPU466 -----

	PPU466 ppu;
};
