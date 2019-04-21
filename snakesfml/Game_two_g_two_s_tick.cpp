#include "Game.h"

void Game::two_g_two_s_tick()
{
	if (cl.getElapsedTime().asMicroseconds() - t1.asMicroseconds() > time1*pow(0.9, snake_1.level - 1) || cl.getElapsedTime().asMicroseconds() - t2.asMicroseconds() > time1*pow(0.9, snake_2.level - 1))
	{
		if (cl.getElapsedTime().asMicroseconds() - t1.asMicroseconds() > time1*pow(0.9, snake_1.level - 1))
		{
			t1 = cl.getElapsedTime();


			if (who_is_win != 2)
			{
				for (int i = snake_1.len - 1; i > 0; --i)
				{
					snake_1.s[i].x = snake_1.s[i - 1].x;
					snake_1.s[i].y = snake_1.s[i - 1].y;
				}
			}

			if (who_is_win != 2)
			{
				if (snake_1.dir == 1) { snake_1.s[0].x++; }
				if (snake_1.dir == 2) { snake_1.s[0].y--; }
				if (snake_1.dir == 3) { snake_1.s[0].x--; }
				if (snake_1.dir == 4) { snake_1.s[0].y++; }
			}
		}
		if (cl.getElapsedTime().asMicroseconds() - t2.asMicroseconds() > time1*pow(0.9, snake_2.level - 1))
		{
			t2 = cl.getElapsedTime();

			if (who_is_win != 1)
			{
				for (int i = snake_2.len - 1; i > 0; --i)
				{
					snake_2.s[i].x = snake_2.s[i - 1].x;
					snake_2.s[i].y = snake_2.s[i - 1].y;
				}
			}

			if (who_is_win != 1)
			{
				if (snake_2.dir == 1) { snake_2.s[0].x++; }
				if (snake_2.dir == 2) { snake_2.s[0].y--; }
				if (snake_2.dir == 3) { snake_2.s[0].x--; }
				if (snake_2.dir == 4) { snake_2.s[0].y++; }
			}
		}
		for (int i = 0; i < 6; ++i)
		{
			fruit.f[i].x = fruit.f[i].x % field.n;
			fruit.f[i].y = fruit.f[i].y % field.m;
		}




		for (int i = 1; i < snake_1.len; ++i)
		{
			if ((snake_1.s[i].x == snake_1.s[0].x && snake_1.s[i].y == snake_1.s[0].y)) //stolknoveniya pervoy zmei s soboy
			{
				if (who_is_win == 0) //ostawlyaem pobedivshuyu zmeyu
				{
					who_is_win = 2;
					snake_1.s.resize(1);
					snake_1.len = 0;
					snake_1.level = 0;
					snake_1.s[0].x = -120;
					snake_1.s[0].y = -120;
					snake_1.score = 0;
				}
				if(who_is_win == 1) //end
				{
					who_is_win = 0;
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
		}

		for (int i = 1; i < snake_2.len; ++i)
		{
			if (snake_2.s[i].x == snake_2.s[0].x && snake_2.s[i].y == snake_2.s[0].y) //stolknovenia vtoroy zmei s soboy
			{
				if (who_is_win == 0)
				{
					who_is_win = 1;
					snake_2.s.resize(1);
					snake_2.len = 0;
					snake_2.level = 0;
					snake_2.s[0].x = -120;
					snake_2.s[0].y = -120;
					snake_2.score = 0;
				}
				if(who_is_win ==  2)
				{
					who_is_win = 0;
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
		}
		//stolknovenia pervoi zmei so stenkami
		if ((snake_1.s[0].x * field.scale + field.d < field.d || snake_1.s[0].x * field.scale + field.scale + field.d > field.w + field.d || snake_1.s[0].y * field.scale + field.d < field.d || snake_1.s[0].y * field.scale + field.scale + field.d> field.h + field.d))
		{
			if (who_is_win == 0)
			{
				who_is_win = 2;
				snake_1.s.resize(1);
				snake_1.len = 0;
				snake_1.level = 0;
				snake_1.s[0].x = -120;
				snake_1.s[0].y = -120;
				snake_1.score = 0;
			}
			if(who_is_win == 1)
			{
				who_is_win = 0;
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
	}
	//stolknovenie vtoroy zmei so stenkami
	if ((snake_2.s[0].x * field.scale + field.d < field.d || snake_2.s[0].x * field.scale + field.scale + field.d > field.w + field.d || snake_2.s[0].y * field.scale + field.d < field.d || snake_2.s[0].y * field.scale + field.scale + field.d> field.h + field.d))
	{
		if (who_is_win == 0)
		{
			who_is_win = 1;
			snake_2.s.resize(1);
			snake_2.len = 0;
			snake_2.level = 0;
			snake_2.s[0].x = -120;
			snake_2.s[0].y = -120;
			snake_2.score = 0;
		}
		if(who_is_win == 2)
		{
			who_is_win = 0;
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
		if ((snake_1.s[0].x == fruit.f[i].x && snake_1.s[0].y == fruit.f[i].y))
		{
			snake_1.s.push_back({ -150,-150 });
			++snake_1.score;

			snake_1.level = 1 + (snake_1.score) / 1;
			fruit.f[i].x = rand() % field.n; //
			fruit.f[i].y = rand() % field.m;
			snake_1.len++;

		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if ((snake_2.s[0].x == fruit.f[i].x && snake_2.s[0].y == fruit.f[i].y))
		{
			snake_2.s.push_back({ -150,-150 });
			++snake_2.score;
			snake_2.level = 1 + (snake_2.score) / 1;
			fruit.f[i].x = rand() % field.n; //
			fruit.f[i].y = rand() % field.m;
			snake_2.len++;

		}
	}

	if (who_is_win == 0)
	{
		for (int i = 0; i < snake_2.s.size(); ++i)
		{
			if (snake_1.s[0].x == snake_2.s[i].x && snake_1.s[0].y == snake_2.s[i].y)
			{
				who_is_win = 2;
				snake_1.s.resize(1);
				snake_1.len = 0;
				snake_1.level = 0;
				snake_1.s[0].x = -120;
				snake_1.s[0].y = -120;
				snake_1.score = 0;
			}
		}

		for (int i = 0; i < snake_1.s.size(); ++i)
		{
			if (snake_2.s[0].x == snake_1.s[i].x && snake_2.s[0].y == snake_1.s[i].y)
			{
				who_is_win = 1;
				snake_2.s.resize(1);
				snake_2.len = 0;
				snake_2.level = 0;
				snake_2.s[0].x = -120;
				snake_2.s[0].y = -120;
				snake_2.score = 0;
			}
		}
	}
}
