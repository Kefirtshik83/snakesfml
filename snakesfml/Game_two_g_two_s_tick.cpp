#include "Game.h"

void Game::two_g_two_s_tick()
{
	if (cl.getElapsedTime().asMicroseconds() - t1.asMicroseconds() > time1*pow(0.9, snake_1.get_level() - 1) || cl.getElapsedTime().asMicroseconds() - t2.asMicroseconds() > time1*pow(0.9, snake_2.get_level() - 1))
	{
		if (cl.getElapsedTime().asMicroseconds() - t1.asMicroseconds() > time1*pow(0.9, snake_1.get_level() - 1))
		{
			t1 = cl.getElapsedTime();
			if (who_is_win != 2)
			{
				for (int i = snake_1.get_len() - 1; i > 0; --i)
				{
					snake_1.set_s(i, snake_1.get_s(i - 1).x, snake_1.get_s(i - 1).y);
				}
			}

			if (who_is_win != 2)
			{
				snake_1_set_dir();
			}
		}
		if (cl.getElapsedTime().asMicroseconds() - t2.asMicroseconds() > time1*pow(0.9, snake_2.get_level() - 1))
		{
			t2 = cl.getElapsedTime();
			if (who_is_win != 1)
			{
				for (int i = snake_2.get_len() - 1; i > 0; --i)
				{
					snake_2.set_s(i, snake_2.get_s(i - 1).x, snake_2.get_s(i - 1).y);
				}
			}

			if (who_is_win != 1)
			{
				snake_2_set_dir();
			}
		}
		for (int i = 0; i < 6; ++i)
		{
			fruit.set_f(i, fruit.get_f(i).x % field.get_n(), fruit.get_f(i).y % field.get_m());
		}




		for (int i = 1; i < snake_1.get_len(); ++i)
		{
			if ((snake_1.get_s(i).x == snake_1.get_s(0).x && snake_1.get_s(i).y == snake_1.get_s(0).y)) //stolknoveniya pervoy zmei s soboy
			{
				if (who_is_win == 0) //ostawlyaem pobedivshuyu zmeyu
				{
					snack_1_died();
				}
				if(who_is_win == 1) //end
				{
					two_s_stand_pos();
				}

			}
		}

		for (int i = 1; i < snake_2.get_len(); ++i)
		{
			if (snake_2.get_s(i).x == snake_2.get_s(0).x && snake_2.get_s(i).y == snake_2.get_s(0).y) //stolknovenia vtoroy zmei s soboy
			{
				if (who_is_win == 0)
				{
					snack_2_died();
				}
				if(who_is_win ==  2)
				{
					two_s_stand_pos();
				}
			}
		}
		//stolknovenia pervoi zmei so stenkami
		if ((snake_1.get_s(0).x * field.get_scale() < 0 || snake_1.get_s(0).x * field.get_scale() + field.get_scale()  > field.get_w()  ||
			snake_1.get_s(0).y * field.get_scale()  < 0 || snake_1.get_s(0).y * field.get_scale() + field.get_scale() > field.get_h() ))
		{
			if (who_is_win == 0)
			{
				snack_1_died();
			}
			if(who_is_win == 1)
			{
				two_s_stand_pos();
			}
		}
	}
	//stolknovenie vtoroy zmei so stenkami
	if ((snake_2.get_s(0).x * field.get_scale()  < 0 || snake_2.get_s(0).x * field.get_scale() + field.get_scale()  > field.get_w()  ||
		snake_2.get_s(0).y * field.get_scale()  < 0 || snake_2.get_s(0).y * field.get_scale() + field.get_scale() > field.get_h()))
	{
		if (who_is_win == 0)
		{
			snack_2_died();
		}
		if(who_is_win == 2)
		{
			two_s_stand_pos();
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if ((snake_1.get_s(0).x == fruit.get_f(i).x && snake_1.get_s(0).y == fruit.get_f(i).y))
		{
			snake_1.s_push_back( -150,-150 );
			snake_1.set_score(snake_1.get_score() + 1);

			snake_1.set_level(1 + (snake_1.get_score()) / 1);
			fruit.set_f(i, rand() % field.get_n(), rand() % field.get_m());
			snake_1.set_len(snake_1.get_len() + 1);

		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if ((snake_2.get_s(0).x == fruit.get_f(i).x && snake_2.get_s(0).y == fruit.get_f(i).y))
		{
			snake_2.s_push_back( -150,-150 );
			snake_2.set_score(snake_2.get_score() + 1);
			snake_2.set_level(1 + (snake_2.get_score()) / 1);
			fruit.set_f(i, rand() % field.get_n(), rand() % field.get_m());
			snake_2.set_len(snake_2.get_len() + 1);

		}
	}

	if (who_is_win == 0)
	{
		for (int i = 0; i < snake_2.get_len(); ++i)
		{
			if (snake_1.get_s(0).x == snake_2.get_s(i).x && snake_1.get_s(0).y == snake_2.get_s(i).y)
			{
				snack_1_died();
			}
		}

		for (int i = 0; i < snake_1.get_len(); ++i)
		{
			if (snake_2.get_s(0).x == snake_1.get_s(i).x && snake_2.get_s(0).y == snake_1.get_s(i).y)
			{
				snack_1_died();
			}
		}
	}
}
