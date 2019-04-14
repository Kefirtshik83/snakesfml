#include "Game.h"

Game::Game() : Snake(1, 2, 1), Fruit()
{
	
}

void Game::start_game()
{
	if (cl.getElapsedTime().asMicroseconds() - t.asMicroseconds() > time1*pow(0.9, level - 1))
	{
		t = cl.getElapsedTime();

		for (int i = len - 1; i > 0; --i)
		{
			s[i].x = s[i - 1].x;
			s[i].y = s[i - 1].y;
		}
		for (int i = 0; i < 6; ++i)
		{
			f[i].x = f[i].x % n;
			f[i].y = f[i].y % m;
		}



		if (dir == 1) { s[0].x++; }
		if (dir == 2) { s[0].y--; }
		if (dir == 3) { s[0].x--; }
		if (dir == 4) { s[0].y++; }

		for (int i = 1; i < len; ++i)
		{
			if (s[i].x == s[0].x && s[i].y == s[0].y)
			{
				flag = -1;
				len = 2;
				s[0].x = 15;
				s[0].y = 10;
				score = 0;
			}
		}
		if (s[0].x * scale + d < d || s[0].x * scale + scale + d > w + d || s[0].y * scale + d < d || s[0].y * scale + scale + d> h + d)
		{
			flag = -1;
			len = 2;
			s[0].x = 15;
			s[0].y = 10;
			score = 0;
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if (s[0].x == f[i].x && s[0].y == f[i].y)
		{
			s.push_back({ -150,-150 });
			++score;
			level = 1 + score / 1;
			f[i].x = rand() % n; //
			f[i].y = rand() % m;
			len++;


		}
	}
}