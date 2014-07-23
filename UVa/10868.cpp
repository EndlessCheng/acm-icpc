#include <iostream>
using namespace std ;

int main()
{
	double k , l , s , w , from_l_to_s , spring_energy , potential_energy ;

	while( cin >> k >> l >> s >> w )
	{
		if( k == 0 && l == 0 && s == 0 && w == 0 )
		{
			break ;
		}

		if( s < l )
		{
			if( 19.62 * s > 100.0 )
			/* If he collides at a speed of more than 10 m/s, he will not survive the impact.*/
			{
				cout << "Killed by the impact." << endl ;
			}
			else
			{
				cout << "James Bond survives." << endl ;
			}
		}
		else
		{
			from_l_to_s = s - l ;

			spring_energy = 0.5 * k * from_l_to_s * from_l_to_s ;
			potential_energy = w * 9.81 * s ;

			/* If spring energy is larger than potential energy at the ground, bond will not touch the ground. */
			if( spring_energy > potential_energy )
			{
				cout << "Stuck in the air." << endl ;
			}
			else
			{
				/* If potential energy subtract spring energy is larger than kinetic energy when the speed is 10.0, bond will died. */
				if( potential_energy - spring_energy > 50.0 * w  )
				{
					cout << "Killed by the impact." << endl ;
				}
				else
				{
					cout << "James Bond survives." << endl ;
				}
			}
		}
	}

	return 0 ;
}
