#include <iostream>

using namespace std;

typedef enum {F16, FORMULA1, MOTOGP} t_racer;

int get_race_distance(void);
float get_race_time(const float distance, const flat accel, const float time_motogp);
void print_race_times(const)



int main()
{

    int dist = get_race_distance();

    const float F16_ACCEL = 7;
    const float F16_VMAX = 2400;

    const float F1_ACCEL = 9;
    const float F1_VMAX = 380;

    const float MGP_ACCEL = 10;
    const float MGP_VMAX = 350;
    const float KMH_TO_MTS = (1000.0/3600.0);

    float time_F16 = get_race_disatance(dist, F16_ACCEL, F16_VMAX*KMH_TO_MTS);
    float time_F1 = get_race_disatance(dist, F1_ACCEL, F1_VMAX*KMH_TO_MTS);
    float time_MGP = get_race_disatance(dist, MGP_ACCEL, MGP_VMAX*KMH_TO_MTS);

    print_race_times(time_F16, time_F1, time_MGP);

    float time_winner;

    t_racer_winner = get_racer_winner(time_F16, time_F1, time_MGP);

    print_race_winner(winner,t_racer_winner);


    cout << "Please enter race distance:" << endl;
    cin>> dist;

    if ( dist%100 != 0)
    {
        cout<< "ERROR: Invalid distance!" << endl;
    }

    cout<< dist << endl;



return 0;

}

int get_race_dist(void)
{
    int race_distance;

    do
    {
        cout <<"Please enter race distance:"<< endl;

    } while()


    return race_distance;
}
