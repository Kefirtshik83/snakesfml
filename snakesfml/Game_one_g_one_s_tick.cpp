#include "Game.h"

void Game::one_g_one_s_tick()
{
	if (cl.getElapsedTime().asMicroseconds() - t1.asMicroseconds() > time1*pow(0.9, snake_1.level - 1))
	{
		t1 = cl.getElapsedTime();

		for (int i = snake_1.len - 1; i > 0; --i)
		{
			snake_1.s[i].x = snake_1.s[i - 1].x;
			snake_1.s[i].y = snake_1.s[i - 1].y;
		}
		for (int i = 0; i < 6; ++i)
		{
			fruit.f[i].x = fruit.f[i].x % field.n;
			fruit.f[i].y = fruit.f[i].y % field.m;
		}



		if (snake_1.dir == 1) { snake_1.s[0].x++; }
		if (snake_1.dir == 2) { snake_1.s[0].y--; }
		if (snake_1.dir == 3) { snake_1.s[0].x--; }
		if (snake_1.dir == 4) { snake_1.s[0].y++; }

		for (int i = 1; i < snake_1.len; ++i)
		{
			if (snake_1.s[i].x == snake_1.s[0].x && snake_1.s[i].y == snake_1.s[0].y)
			{
				play = 0;
				one_player = 0;
				two_player = 0;
				one_snake = 0;
				two_snake = 0;
				snake_1.s.resize(2);
				snake_1.len = 2;
				snake_1.level = 1;
				snake_1.s[0].x = 15;
				snake_1.s[0].y = 10;
				snake_1.score = 0;
				snake_2.s.resize(2);
				snake_2.len = 2;
				snake_2.level = 1;
				snake_2.s[0].x = 18;
				snake_2.s[0].y = 10;
				snake_2.score = 0;
			}
		}
		if (snake_1.s[0].x * field.scale + field.d < field.d || snake_1.s[0].x * field.scale + field.scale + field.d > field.w + field.d || snake_1.s[0].y * field.scale + field.d < field.d || snake_1.s[0].y * field.scale + field.scale + field.d> field.h + field.d)
		{
			play = 0;
			one_player = 0;
			two_player = 0;
			one_snake = 0;
			two_snake = 0;
			snake_1.s.resize(2);
			snake_1.len = 2;
			snake_1.level = 1;
			snake_1.s[0].x = 15;
			snake_1.s[0].y = 10;
			snake_1.score = 0;
			snake_2.s.resize(2);
			snake_2.len = 2;
			snake_2.level = 1;
			snake_2.s[0].x = 18;
			snake_2.s[0].y = 10;
			snake_2.score = 0;
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if (snake_1.s[0].x == fruit.f[i].x && snake_1.s[0].y == fruit.f[i].y)
		{
			snake_1.s.push_back({ -150,-150 });
			++snake_1.score;
			snake_1.level = 1 + snake_1.score / 1;
			fruit.f[i].x = rand() % field.n; //
			fruit.f[i].y = rand() % field.m;
			snake_1.len++;


		}
	}
}
