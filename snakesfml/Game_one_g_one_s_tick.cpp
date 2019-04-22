#include "Game.h"

void Game::one_g_one_s_tick()
{
	if (cl.getElapsedTime().asMicroseconds() - t1.asMicroseconds() > time1*pow(0.9, snake_1.get_level() - 1))
	{
		t1 = cl.getElapsedTime();

		for (int i = snake_1.get_len() - 1; i > 0; --i)
		{
			snake_1.set_s(i, snake_1.get_s(i - 1).x, snake_1.get_s(i - 1).y);
		}
		for (int i = 0; i < 6; ++i)
		{
			fruit.set_f(i, fruit.get_f(i).x % field.get_n(), fruit.get_f(i).y % field.get_m());
		}
		snake_1_set_dir();
		for (int i = 1; i < snake_1.get_len(); ++i)
		{
			if (snake_1.get_s(i).x == snake_1.get_s(0).x && snake_1.get_s(i).y == snake_1.get_s(0).y)
			{
				two_s_stand_pos();
			}
		}
		if (snake_1.get_s(0).x * field.get_scale()  < 0 || snake_1.get_s(0).x * field.get_scale() + field.get_scale() > field.get_w()  ||
			snake_1.get_s(0).y * field.get_scale() < 0 || snake_1.get_s(0).y * field.get_scale() + field.get_scale() > field.get_h())
		{
			two_s_stand_pos();
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if (snake_1.get_s(0).x == fruit.get_f(i).x && snake_1.get_s(0).y == fruit.get_f(i).y)
		{
			snake_1.s_push_back( -150 ,-150 );
			snake_1.set_score(snake_1.get_score() + 1);
			snake_1.set_level(1 + snake_1.get_score() / 1);
			fruit.set_f(i, rand() % field.get_n(), rand() % field.get_m());
			snake_1.set_len(snake_1.get_len() + 1);
		}
	}
}
