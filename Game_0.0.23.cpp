// Game 0.0.23.cpp

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <ctime>

using namespace std;



int short_combat_stats = 0;
double health = 100;
double health_b = 0;
int exp = 0; // not in the code yet
double stamina = 0;
double stamina_used = 0;
int nerves = 0;
int insanity = 0;
double hand_to_hand = 0;
int fear = 0;
int empathy = 0;
double luck = 0;
int quarter = 0;
int action;
int action2;
char answer;
int mood = 0;
int has_money = 0;
int age = 0;
int movement_action = 0;
int path = 0;
int rock = 0;
int hammer = 0;
double penalty_agility_weapon = 0;
double boost_strength_weapon = 0;
bool melee = 0;
bool has_weapon = 0;
bool balance = 1;
double punk_weapon_range = 0;

double agility = 0;
double strength = 0;
double speed = 0;

double ranged_range = 0;
double ranged_accuracy = 0;
double ranged_strength = 0;


double light_chain_range = 1;
double light_chain_mass = 1;

double mass = 1;
double throw_range = speed / mass;
int weapon_quantity;

int posx = 0; // not anymore a Table variable
int posy = 0; // not anymore a Table variable
int old_posx = 0;
int old_posy = 0;

int map_y = 10;
int map_x = 10;
int di = 0;
int dj = 0;


bool police_report_skinny_punk = 0;
bool win_flag = 0;

bool coward = 0;


int cookie [5] = {1, 4, 7, 10, 20};
int cookie_price [5] = {1, 3, 5, 7, 15};

char name_character[20];


char new_answer;
char new_save[15];
char load_game[15];
char direction;

string weapon;


void dark_alley ();
void barking_dog ();
void running_dog ();
void NPC ();
void home ();
void city ();
void money ();
void random ();
void save ();
void save_specific (char);
void shop ();
void gym ();
void punk ();
void bum ();
void skinny_punk ();
void chain_skinny_punk ();
void skinhead ();
void rock_event ();
void hammer_event ();
void random_punk ();
void boxing_training ();
void delay ();
void punk_intro (string punk_introduction, double *punk_distance);


void working_punk ();
void older_lady ();
void kitten ();
void stats ();
void stats_ref (double & ref3_punk_distance);
void movement ();
void you_missed ();
void base_attacks_menu ();
void simple_attacks_menu ();
void drop_weapon ();
void equip_your_weapon ();

void weapon_none ();
void weapon_rock ();
void weapon_hammer ();

void map ();
void for_map();

void punk_mechanics 
(
bool param_is_ranged, double param_punk_health, double param_punk_fear, double param_punk_strength, double param_punk_agility, double param_punk_luck, double param_punk_speed, double & ref1_punk_distance, string param_punk_punch_attempt, string param_punk_kick_attempt,
string param_punk_hit, string param_punk_miss, string param_punk_running, string param_punk_territory, string param_punk_attack_fail
);

void random_fight ();

void punk_hit_for (double & ref_total_punk_damage, double & ref_param_punk_health);

bool all_dog_stamina (double param_dog_stamina);
bool all_dog_nerves (double param_dog_nerves);

int damage_multiplication ();

int main ()
{
	
	cout << "Do you want to load last quick save? If yes type '1'\n";
	cin >> answer;
	
	if (answer == '1')
	{
		
		ifstream inload;
		
		inload.open("save_out.dat");
		inload >> health >> exp >> stamina >> nerves >> insanity >> hand_to_hand >> fear >> empathy >> luck >> quarter >> mood >> agility >> strength >> age >> name_character >> speed;
		
		inload.close();
		
		cout << "Saved data has been loaded. \n";
	}
	else
	{
		cout << "Do you want to load a different save? If yes type '1' \n";
		cin >> answer;
	
		if (answer == '1')
		{
		
			cout << "Type in the name of the file, but not longer than 14 signs: \n";
					cin >> load_game;
			
			ifstream load_spec;
			
			load_spec.open(load_game);
			load_spec >> health >> exp >> stamina >> nerves >> insanity >> hand_to_hand >> fear >> empathy >> luck >> quarter >> mood >> agility >> strength >> age >> name_character >> speed;
		
			load_spec.close();
		
			cout << "Saved data has been loaded. \n";
		}
	
	}
	
	
	if (age == 0)
	{
		cout << "How old is your character? \n";
		cin >> age;
		cin.get();
	}

	if (strlen(name_character) == 0)
	{
		cout << "What is the name of your character? \n";
		cin.get(name_character, 20);
	}
	
	stats ();
	delay ();
			
random ();
	
	return 0;
	
	
}

void random ()
	{
		using namespace std;
		
		int random_n;
			
		save ();
			
		srand (time(NULL));
		
		random_n = rand() % 19 + 1;
		
		if (health == 0)
			{
				cout << "Game over" ;
				abort();
			}
		else if (health < 0)
			{
				cout << "Game over" ;
				abort();
			}
				
		else
		{
				
			void movement ();
			
			cout << "\n" << "This is what happens next: \n";
			if (random_n == 1)
				{
					dark_alley ();
				}
			else if (random_n == 2)
				{
					money ();
				}	
			else if (random_n == 3)
					barking_dog ();
			else if (random_n == 4)
				{
					if (path == 0)
					{
						shop ();
					}
					else
						random();
				}
			else if (random_n == 5)
				{
					if (path == 0)
					{
						gym ();	
					}
					else
						random ();
				}
			else if (random_n == 6)
					punk ();
			else if (random_n == 7)
					skinny_punk ();
			else if (random_n == 8)
					older_lady ();
			else if (random_n == 9)
					working_punk ();
			else if (random_n == 10)
					running_dog ();
			else if (random_n == 11)
					bum ();
			else if (random_n == 12)
					skinhead ();
			else if (random_n == 13)
					rock_event ();
			else if (random_n == 14)
					random_punk ();
			else if (random_n == 15)
					kitten ();
			else if (random_n == 16)
					boxing_training ();
			else if (random_n == 17)
					hammer_event ();
			else if (random_n == 18)
					chain_skinny_punk ();
			else if (random_n == 19)
					delay ();
			else
				{
					if (path == 0)
					{
							home ();
					}
					else
						random ();
				}
		}
	}

void random_fight 
(
bool param_is_ranged, double param_punk_health, double param_punk_fear, double param_punk_strength, double param_punk_agility, double param_punk_luck, double param_punk_speed, double & ref2_punk_distance, string param_punk_punch_attempt, string param_punk_kick_attempt, 
string param_punk_hit, string param_punk_miss, string param_punk_running, string param_punk_territory, string param_punk_attack_fail
)
	{
		
		using namespace std;
		
		// double skinhead_agility = 0.01;
		int random_new;
		
		// srand (time(NULL));       For some reason it was causing the result to be constant
		random_new = rand() % 3 + 1;
		cin.get();
		
		if (health == 0)
			{
				cout << "Game over";
				abort();
			}
		else if (health < 0)
		{
			cout << "Game over";
			abort();
		}
		
		
		else
		{
			if (balance == 0)
			cout << "The opponent fell to the ground! \n";
			else
			cout << "The opponent attacks! \n";
			cin.get();
			
			if (balance == 0)
			{
				cout << "The opponent lost his turn! \n";
				balance = 1;
			}
			
			else if (param_is_ranged == 1 && ref2_punk_distance < punk_weapon_range)
			{
				cout << "The opponent moves away from you! \n";
				ref2_punk_distance = ref2_punk_distance + param_punk_speed;
				if (ref2_punk_distance > punk_weapon_range)
				{
					ref2_punk_distance = punk_weapon_range;
				}
				cout << param_punk_hit << param_punk_speed * 3.14 * (ref2_punk_distance / punk_weapon_range) * punk_weapon_range * punk_weapon_range;
				health = health - param_punk_speed * 3.14 * (ref2_punk_distance / punk_weapon_range) * punk_weapon_range * punk_weapon_range;
			}
			
			else if (random_new == 1 && ref2_punk_distance == 0)
				{
					cout << param_punk_punch_attempt;
					if (param_punk_agility > agility)
						{
							health_b = health;
							cout << param_punk_hit << param_punk_strength * param_punk_speed - hand_to_hand << "! \n";
							health = health - param_punk_strength * param_punk_speed + hand_to_hand;

							if (health > health_b)
							{
								health = health_b;
							}
						}
					
					else
						cout << param_punk_miss;
				}
			else if (random_new == 2 && ref2_punk_distance == 0)
				{
					cout << param_punk_kick_attempt;
					if (param_punk_agility > agility + hand_to_hand)
						{
							health_b = health;
							cout << param_punk_hit << 2 * param_punk_strength * param_punk_speed - hand_to_hand << "! \n";
							health = health - 2 * param_punk_strength * param_punk_speed + hand_to_hand;
							
							if (health > health_b)
							{
								health = health_b;
							}
						}
					
					else
						cout << param_punk_miss;
				}
			else if (random_new == 3 && param_punk_luck < luck && ref2_punk_distance == 0)
				{
					cout << param_punk_attack_fail;
				}
			else if (param_is_ranged = 0 && ref2_punk_distance == 0)
				{
					cout << param_punk_punch_attempt;
					if (param_punk_agility > agility)
						{
							health_b = health;
							cout << param_punk_hit << param_punk_strength - hand_to_hand << "! \n";
							health = health - param_punk_strength + hand_to_hand;
							
							if (health > health_b)
							{
								health = health_b;
							}
						}
					
					else
						cout << param_punk_miss;
				}
			else if (param_is_ranged == 0 && ref2_punk_distance > 0)
				{
					ref2_punk_distance = ref2_punk_distance - param_punk_speed;
					if (ref2_punk_distance < 0)
					{
						ref2_punk_distance = 0;
					}
				}
		
		}
	
	stats_ref (ref2_punk_distance);
	
	}



void punk_mechanics 
(
bool param_is_ranged, double param_punk_health, double param_punk_fear, double param_punk_strength, double param_punk_agility, double param_punk_luck, double param_punk_speed, double & ref1_punk_distance, string param_punk_punch_attempt, string param_punk_kick_attempt, 
string param_punk_hit, string param_punk_miss, string param_punk_running, string param_punk_territory, string param_punk_attack_fail
)
{
	using namespace std;
	
	cout << "1. Start a fight. \n";
	cout << "2. Run. \n";
	
	cin >> action;
	
	short_combat_stats = 1;
	
	if (action == 1)
		{
			++nerves;
				
			while (param_punk_health > 0 && health > 0 && param_punk_fear < 1)
			{
			
				if (param_punk_fear < 1)
					{
					random_fight (param_is_ranged, param_punk_health, param_punk_fear, param_punk_strength, param_punk_agility, param_punk_luck, param_punk_speed, ref1_punk_distance, param_punk_punch_attempt, param_punk_kick_attempt,
					param_punk_hit, param_punk_miss, param_punk_running, param_punk_territory, param_punk_attack_fail);
					}		
				else
					{
					cout << param_punk_running;
					param_punk_fear = param_punk_fear + 1;
					}
					
			
			if (ref1_punk_distance < 0.5)
			{
				cout << "1. Show hand to hand menu. \n";
			}
			else if (ref1_punk_distance > 0.5)
			{
				cout << "1. Stand still. \n";
			}
			
			if (param_is_ranged == 1)
			cout << "2. Create a distance. \n";
			else if (speed > param_punk_speed && ref1_punk_distance == 0)
			cout << "2. Create a distance. \n";
			
			
			if (speed > param_punk_speed && ref1_punk_distance != 0)
			cout << "2. Create a distance. \n";
			if (ref1_punk_distance > 0)
			cout << "3. Close the distance. \n";
			if (ref1_punk_distance > 0)
			{
				if (melee > 0 && weapon_quantity > 0)
				{	
					
						if (weapon_quantity == 1)
						{	
							cout << "4. Throw the "<< weapon <<" at him! \n";
						}
						else if (weapon_quantity > 1)
						{
							cout << "4. Throw a " << weapon << " at him! \n";
						}
						
				}
				else
				{
					cout << "You have no projectiles! \n";
				}
			}
			if (speed > param_punk_speed)
			{
				cout << "5. Run! \n";
			}
			
			
			cin >> action2;
			
				if (health < 0)
				{
					cout << "Game Over! \n";
					abort();
				}
				else if (action2 == 1 && ref1_punk_distance < 0.5)
				{
					double total_punk_damage;
					base_attacks_menu ();
					cin >> action2;	
				
					if (action2 == 1 && ref1_punk_distance < 0.5)
					{
						if (action2 == 1 && agility > param_punk_agility)
						{
							cout << "############################\n";
							cout << "# You hit him in the head! #\n";
							cout << "############################\n";
							
							punk_hit_for (total_punk_damage, param_punk_health);
							
							hand_to_hand = hand_to_hand + 0.01;
						}
						else
						{
							you_missed ();
						}
					}
					else if (action2 == 2 && ref1_punk_distance <= 0.5)
					{
						cout << "#######################################################\n";
						cout << "# You hit him in the torso with the " << weapon << "! #\n";
						cout << "#######################################################\n";
						int rand_local = 0;
						rand_local = rand() % 100 + 1;
						if (rand_local < (agility + luck) - param_punk_agility)
						{
							param_punk_health = param_punk_health - (strength + hand_to_hand);
							cout << "You dealt a critical hit! \n";
						}
						
						punk_hit_for (total_punk_damage, param_punk_health);
						
//						total_punk_damage = mass * speed * damage_multiplication ();
//						cout << "!!! DEBUG: dmg to the punk = " << total_punk_damage << " !!!     Punk health left " << param_punk_health <<" !!!\n";
//						param_punk_health = param_punk_health - total_punk_damage;
						
						hand_to_hand = hand_to_hand + 0.01;
						speed = speed + 0.0001;
	
					}
					else if (action2 == 3 && ref1_punk_distance < 0.5)
					{
						if (agility > 2 * param_punk_agility)
						{
							cout << "###############################\n";
							cout << "# You kicked him in the head! #\n";
							cout << "###############################\n";
							
							punk_hit_for (total_punk_damage, param_punk_health);
							
							hand_to_hand = hand_to_hand + 0.01;
							agility = agility + 0.001;
						}
						else
						{
							you_missed ();
						}
					}
					else if (action2 == 4 && ref1_punk_distance < 0.5)
					{
				
						if (agility > param_punk_agility)
						{
							cout << "########################################################\n";
							cout << "# You kicked him in the torso with the "<< weapon <<"! #\n";
							cout << "########################################################\n";
							
							punk_hit_for (total_punk_damage, param_punk_health);
							
							hand_to_hand = hand_to_hand + 0.01;
						}
						else
						{
							you_missed ();
						}
					}
					else if (action2 == 5 && ref1_punk_distance < 0.5)
					{
				
						if (agility > param_punk_agility)
						{
						cout << "###############################\n";
						cout << "# You kicked him in the legs! #\n";
						cout << "###############################\n";
						
						punk_hit_for (total_punk_damage, param_punk_health);
						
						param_punk_strength = param_punk_strength - (strength + hand_to_hand);
						hand_to_hand = hand_to_hand + 0.01;
						}
						else
						{
						you_missed ();
						}
					}
					else if (action2 == 6 && ref1_punk_distance < 0.5)
					{
				
						if (agility > param_punk_agility * 2)
						{
							cout << "############################\n";
							cout << "# You hit him in the arms! #\n";
							cout << "############################\n";
							
							punk_hit_for (total_punk_damage, param_punk_health);
							
							param_punk_strength = param_punk_strength - (strength + 2 * hand_to_hand);
							hand_to_hand = hand_to_hand + 0.01;
						}
						else
						{
							you_missed ();
						}
				
					}
					else if (action2 == 7 && ref1_punk_distance < 0.5)
					{
						if (agility > param_punk_agility * 4)
						{
							cout << "###############################\n";
							cout << "# You kicked him in the arms! #\n";
							cout << "###############################\n";
							
							punk_hit_for (total_punk_damage, param_punk_health);
							
							param_punk_strength = param_punk_strength - ( 2 * strength + hand_to_hand);
							hand_to_hand = hand_to_hand + 0.01;
						}
						else
						{
							you_missed ();
						}
					}
					else if (action2 == 8 && ref1_punk_distance < 0.5)
					{
						if (agility > param_punk_agility)
						{
							cout << "############################\n";
							cout << "# He lost his balance! #\n";
							cout << "############################\n";
							balance = 0;
						}
						else
						{
							cout << "You didn't do it. \n";
							speed += 0.0001;
							agility += 0.0001;
						}
					}
						
				}
				else if (action == 1 && ref1_punk_distance > 0.5)
				{
					cout << "You skipped your turn \n";
				}
				else if (action2 == 2 && param_is_ranged == 1)
				{
					ref1_punk_distance = ref1_punk_distance + speed;
				}
				else if (action2 == 2 && speed > param_punk_speed)
				{
				ref1_punk_distance = ref1_punk_distance + speed;
				}
				else if (action2 == 4 && ref1_punk_distance > 0)
				{
					
					if (weapon == "rock")
					{
						--rock;
						weapon_quantity = rock;
					}
					
					if (weapon == "hammer")
					{
						--hammer;
						weapon_quantity = hammer;
					}
					
					if (weapon_quantity == 0)
					{
						weapon_none();
					}
					
					if (speed + strength < 1)
					{
						param_punk_health = param_punk_health - mass * speed;
						if (strength < 1)
						strength = strength + 0.1;
						if (speed < 1)
						speed = speed + 0.1;
					}
					else
					{
						param_punk_health = param_punk_health - mass * speed;
						strength = strength + 0.1;
						speed = speed + 0.1;
					}
				}			
				else if (action2 == 3 && ref1_punk_distance > 0)
					{
						ref1_punk_distance = ref1_punk_distance - speed;
						if (ref1_punk_distance < 0)
						{
							ref1_punk_distance = 0;
						}
					}
				else if (action2 == 5 && speed > param_punk_speed)
					{
						cout << param_punk_territory;
						coward = 1;
						break;
					}	
				
			// cin.get();  // this line seems not to work for some reason -> or perhaps it worked after all
			stats_ref (ref1_punk_distance);
			
			}
		
		if (coward == 0)
		{
		cout << "You win! \n";
		}
		coward = 0;
		
		if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
		
		}
	else
		cout << param_punk_territory;
		stamina = stamina + 0.001;
		speed = speed + 0.0001;
		++fear;
	
	stats_ref (ref1_punk_distance);
	if (path == 0)
	{
		random ();	
	}
	else if (path == 1)
	{
		posx = old_posx;
		posy = old_posy;
		
		city ();
	}
	
	short_combat_stats = 0;
	cin.get();

	}

void punk_hit_for (double & ref_total_punk_damage, double & ref_param_punk_health)
{
	ref_total_punk_damage = mass * speed * damage_multiplication ();
	cout << "!!! DEBUG: dmg to the punk = " << ref_total_punk_damage << " !!!     Punk health left " << ref_param_punk_health <<" !!!\n";
	ref_param_punk_health = ref_param_punk_health - ref_total_punk_damage;
}


int damage_multiplication ()
{
	int random_n;
	random_n = rand() % 100 + 1;
		
	double damage_multiplier;
	
	if (random_n == 1)
	{
		damage_multiplier = 1;
	}
	else if (random_n > 1 && random_n <= 10)
	{
		damage_multiplier = 1.1 + luck;
	}
	else if (random_n > 10 && random_n <= 50)
	{
		damage_multiplier = 1.5 + luck;
	}
	else if (random_n > 50 && random_n <= 90)
	{
		damage_multiplier = 2 + luck;
	}
	else if (random_n > 90 && random_n <= 100)
	{
		damage_multiplier = 3 + luck;
	}
	
	return damage_multiplier;
	
}

void simple_attacks_menu ()
{
	cout << "1. Punch him in the head. \n";
	cout << "2. Punch him in the torso. \n";
	cout << "3. Guard against next attack. \n";
}

void boxing_training ()
{
	using namespace std;
	
	short_combat_stats = 1;
	
	cout << "You come across a middle aged man. \n";
	cout << "'I can teach you how to fight', he says. \n";
	cout << "1. Sure, I want to learn. \n";
	cout << "2. No thank you. \n";
	
	cin >> answer;
	
	if (answer == '1')
	{
	
		double boxing_health = 0;
		int random_g = 0;
		
		simple_attacks_menu ();
		
		char action = 0;
		cin >> action;
		
		boxing_health = health;
		
		while (health > 30 && health + 10 > boxing_health)
		{
			switch (action)
			{
				case '1'	:	cout << "You practice a punch in the head! \n"; agility = agility + 0.0001; strength = strength + 0.00001; hand_to_hand = hand_to_hand + 0.00001;
							
							if (agility + strength + hand_to_hand < 1)
							{
								health = health - 1 + agility + strength + hand_to_hand;
							}
							else
							{
								boxing_health = boxing_health + 1;
							}
							break;
				case '2'	:	cout << "You practice a punch in the torso! \n"; agility = agility + 0.00001; strength = strength + 0.00001; hand_to_hand = hand_to_hand + 0.00001;
							
							if (agility + strength + hand_to_hand < 1)
							{
								health = health - 1 + agility + strength + hand_to_hand;
							}
							else
							{
								boxing_health = boxing_health + 1;
							}
							break;
				case '3'	:	cout << "You practice a guard against the next attack! \n";
							
							random_g = rand() % 100;
							if (random_g < luck + agility + hand_to_hand)
							{
								cout << "You defended yourself against the attack! \n";
								luck = luck + 0.00001;
							}
							else
							{
								if (agility + strength + hand_to_hand < 1)
								{
									health = health - 1 + agility + strength + hand_to_hand;
									hand_to_hand = hand_to_hand + 0.00001;
									cout << "Ouch! \n";
								}
								else
								{
									boxing_health = boxing_health + 1;
									hand_to_hand = hand_to_hand + 0.00001;
									cout << "You're hard to hit buddy! \n";
								}
							}
							break;
				default	:	cout << "There is no such action! \n";
							
			}
			stats ();
			simple_attacks_menu ();
			cin >> action;
		}
	}
	else
	cout << "'Okay, I'll be around'. \n";
	
	
	stats ();
	if (path == 0)
	{	
		short_combat_stats = 0;
		random ();	
	}
	else if (path == 1)
	{
		posx = old_posx;
		posy = old_posy;
		
		short_combat_stats = 0;
			
		city ();
	}
	
}

void base_attacks_menu ()
{
		cout << "1. Hit him in the head. \n";
		cout << "2. Hit him in the torso. \n";
		cout << "3. Kick him in the head. \n";
		cout << "4. Kick him the torso. \n";
		cout << "5. Kick him in the legs. \n";
		cout << "6. Hit him in the arms. \n";
		cout << "7. Kick him in the arms. \n";
		cout << "8. Make him lose balance. \n";
}

void punk_intro (string punk_introduction, double *p_punk_distance)
{
cout << punk_introduction  << "He is " << *p_punk_distance << " meters from you. His address in the memory is " << p_punk_distance << "\n";
}

void bum ()
{
	using namespace std;
	bool is_ranged = 0;
	double punk_health = 1 + hand_to_hand + strength + agility;
	double punk_strength = 0.1 + hand_to_hand + strength + agility;
	double punk_fear = 0;
	double punk_agility = 0.01;
	double punk_luck = 0.01;
	double punk_speed = 0.001;
	double punk_distance = 0;
	
	double * p_punk_distance;
	p_punk_distance = &punk_distance;
	
	string punk_punch_attempt = "The REDACTED attempts to punch you!";
	string punk_kick_attempt = "The REDACTED attempts to kick you!";
	string punk_hit = "The REDACTED hits you for ";
	string punk_miss = "The REDACTED missed! \n";
	string punk_running = "The REDACTED is running away from you his pants wet! \n";
	string punk_territory = "Next time bring me some booze! \n";
	string punk_attack_fail = "The REDACTED farts and gets distracted! \n";
	string punk_introduction = "A REDACTED lies in your way. \n";
	
	punk_intro (punk_introduction, &punk_distance);
	
	punk_mechanics (is_ranged, punk_health, punk_fear, punk_strength, punk_agility, punk_luck, punk_speed, punk_distance, punk_punch_attempt, punk_kick_attempt, punk_hit, punk_miss, punk_running, punk_territory, punk_attack_fail);
}


void skinny_punk ()
{
	using namespace std;
	bool is_ranged = 0;
	double punk_health = 3 + hand_to_hand + strength + agility;
	double punk_strength = 1 + hand_to_hand + strength + agility;
	double punk_fear = 0;
	double punk_agility = 0.1;
	double punk_luck = 0.1;
	double punk_speed = 0.01;
	double punk_distance = 0;
	
	double * p_punk_distance;
	p_punk_distance = &punk_distance;
	
	string punk_punch_attempt = "The skinny punk attempts to punch you!";
	string punk_kick_attempt = "The skinny punk attempts to kick you!";
	string punk_hit = "The skinny punk hits you for ";
	string punk_miss = "The skinny punk missed! \n";
	string punk_running = "The punk is running away from you his pants wet! \n";
	string punk_territory = "Yeah! Run! It's punk territory! \n";
	string punk_attack_fail = "The skinny punk rubs his REDACTED and loses his turn! \n";
	string punk_introduction = "A skinny looking punk is standing in your way.\n";
	
	punk_intro (punk_introduction, &punk_distance);
	
	punk_mechanics (is_ranged, punk_health, punk_fear, punk_strength, punk_agility, punk_luck, punk_speed, punk_distance, punk_punch_attempt, punk_kick_attempt, punk_hit, punk_miss, punk_running, punk_territory, punk_attack_fail);
}

void chain_skinny_punk ()
{
	using namespace std;
	bool is_ranged = 1;
	double punk_health = 3;
	double punk_strength = 1;
	double punk_fear = 0;
	double punk_agility = 0.1;
	double punk_luck = 0.1;
	double punk_speed = 0.01;
	double punk_distance = 0;
	
	double * p_punk_distance;
	p_punk_distance = &punk_distance;
	
	punk_weapon_range = light_chain_range;
	
	string punk_punch_attempt = "The skinny punk attempts to punch you!";
	string punk_kick_attempt = "The skinny punk attempts to kick you!";
	string punk_hit = "The skinny punk hits with the chain you for ";
	string punk_miss = "The skinny punk missed! \n";
	string punk_running = "The punk is running away from you his pants wet! \n";
	string punk_territory = "Yeah! Run! It's punk territory! \n";
	string punk_attack_fail = "The chain wraps around skinny punk's arm and he loses his turn! \n";
	string punk_introduction = "A skinny looking punk with a chain is standing in your way.\n";
	
	punk_intro (punk_introduction, &punk_distance);
	
	punk_mechanics (is_ranged, punk_health, punk_fear, punk_strength, punk_agility, punk_luck, punk_speed, punk_distance, punk_punch_attempt, punk_kick_attempt, punk_hit, punk_miss, punk_running, punk_territory, punk_attack_fail);
}

//void skinny_punk2 ()
//{
//	using namespace std;
//	double punk_health = 3 + hand_to_hand + strength + agility;
//	double punk_strength = 1 + hand_to_hand + strength + agility;
//	double punk_fear = 0;
//	double punk_agility = 0.1;
//  double punk_luck = 0.1;
//	double punk_distance = 0;
	
//	string punk_punch_attempt = "The skinny punk attempts to punch you!";
//	string punk_kick_attempt = "The skinny punk attempts to kick you!";
//	string punk_hit = "The skinny punk hits you for ";
//	string punk_miss = "The skinny punk missed! \n";
//	string punk_running = "The punk is running away from you his pants wet! \n";
//	string punk_territory = "Yeah! Run! It's punk territory! \n";
	
//	path = 1;
//	cout << "\n";
//	cout << "A skinny looking punk is standing in your way.\n";
//	punk_mechanics (punk_health, punk_fear, punk_strength, punk_agility, punk_luck, punk_punch_attempt, punk_kick_attempt, punk_hit, punk_miss, punk_running, punk_territory, punk_attack_fail);
//}

void punk ()
{
	using namespace std;
	bool is_ranged = 0;
	double punk_health = 7 + hand_to_hand + strength + agility;
	double punk_strength = 2 + hand_to_hand + strength + agility;
	double punk_fear = 0;
	double punk_agility = 0.2;
	double punk_luck = 0.2;
	double punk_speed = 0.1;
	double punk_distance = 0;
	
	double * p_punk_distance;
	p_punk_distance = &punk_distance;
	
	string punk_punch_attempt = "The punk attempts to punch you!";
	string punk_kick_attempt = "The punk punk attempts to kick you!";
	string punk_hit = "The punk hits you for ";
	string punk_miss = "The punk missed! \n";
	string punk_running = "The punk is running away from you his pants wet! \n";
	string punk_territory = "Yeah! Run! It's punk territory! \n";
	string punk_attack_fail = "punk_attack_fail";
	string punk_introduction = "A punk is standing in your way.\n";
	
	punk_intro (punk_introduction, &punk_distance);
	
	punk_mechanics (is_ranged, punk_health, punk_fear, punk_strength, punk_agility, punk_luck, punk_speed, punk_distance, punk_punch_attempt, punk_kick_attempt, punk_hit, punk_miss, punk_running, punk_territory, punk_attack_fail);
}

void working_punk ()
{
	using namespace std;
	bool is_ranged = 0;
	double punk_health = 14 + hand_to_hand + strength + agility;
	double punk_strength = 4 + hand_to_hand + strength + agility;
	double punk_fear = 0;
	double punk_agility = 0.4;
	double punk_luck = 0.4;
	double punk_speed = 0.2;
	double punk_distance = 0;
	
	double * p_punk_distance;
	p_punk_distance = &punk_distance;
	
	string punk_punch_attempt = "The working-out punk attempts to punch you!";
	string punk_kick_attempt = "The working-out punk attempts to kick you!";
	string punk_hit = "The working-out punk hits you for ";
	string punk_miss = "The working-out punk missed! \n";
	string punk_running = "The punk is running away from you his pants wet! \n";
	string punk_territory = "Yeah! Run! It's punk territory! \n";
	string punk_attack_fail = "punk_attack_fail";
	string punk_introduction = "A working out punk is doing push-ups in your way.\n";
	
	punk_intro (punk_introduction, &punk_distance);

	punk_mechanics (is_ranged, punk_health, punk_fear, punk_strength, punk_agility, punk_luck, punk_speed, punk_distance, punk_punch_attempt, punk_kick_attempt, punk_hit, punk_miss, punk_running, punk_territory, punk_attack_fail);
}

void skinhead ()
{
	
	using namespace std;
	bool is_ranged = 0;
	double punk_health = 20 + hand_to_hand + strength + agility;
	double punk_strength = 8 + hand_to_hand + strength + agility;
	double punk_fear = 0;
	double punk_agility = 0.8;
	double punk_luck = 0.8;
	double punk_speed = 0.5;
	double punk_distance = 0;
	
	double * p_punk_distance;
	p_punk_distance = &punk_distance;
	
	string punk_punch_attempt = "The skinhead attempts to punch you!";
	string punk_kick_attempt = "The skinhead attempts to kick you!";
	string punk_hit = "The skinhead hits you for ";
	string punk_miss = "The skinhead missed! \n";
	string punk_running = "The skinhead is running away from you his pants wet! \n";
	string punk_territory = "You're running like a REDACTED! \n";
	string punk_attack_fail = "punk_attack_fail";
	string punk_introduction = "A skinhead is standing in your way.\n";
	
	punk_intro (punk_introduction, &punk_distance);

	punk_mechanics (is_ranged, punk_health, punk_fear, punk_strength, punk_agility, punk_luck, punk_speed, punk_distance, punk_punch_attempt, punk_kick_attempt, punk_hit, punk_miss, punk_running, punk_territory, punk_attack_fail);
	
}

void random_punk ()
{
	using namespace std;
	
	int random_e;
	
	bool is_ranged = 0;
	
	random_e = rand() % 100 + 1;
	double punk_health = random_e;
	
	random_e = rand() % 100 + 1;
	double punk_strength = random_e;
	
	double punk_fear = 0;
	
	random_e = rand() % 100 + 1;
	double punk_agility = random_e;
	
	random_e = rand() % 100 + 1;
	double punk_luck = random_e;
	
	random_e = rand() % 100 + 1;
	double punk_speed = random_e;
	
	double punk_distance = 0;
	
	
//	double * p_punk_distance;
//	p_punk_distance = &punk_distance;
	
	
	string punk_punch_attempt = "The skinhead attempts to punch you!";
	string punk_kick_attempt = "The skinhead attempts to kick you!";
	string punk_hit = "The skinhead hits you for ";
	string punk_miss = "The skinhead missed! \n";
	string punk_running = "The skinhead is running away from you his pants wet! \n";
	string punk_territory = "You're running like a REDACTED! \n";
	string punk_attack_fail = "punk_attack_fail";
//	string punk_introduction = 

	if (punk_health + punk_strength + punk_agility + punk_luck + punk_speed > 1.1 * (health + strength + agility + luck + speed) )
	{
		cout << "A deadly hostile is standing in your way!\n";
	}
	else
	{
		cout << "A hostile is standing in your way.\n";
		if (punk_strength > strength) cout << "His muscles seem bigger than yours. \n";
		if (punk_health > health) cout << "He looks more healthy than you. \n";
		if (punk_agility > agility) cout << "He is more nimble than you. \n";
		if (punk_speed > speed) cout << "Looks like you won't run from him if you piss him off'. \n";
	}
	punk_mechanics (is_ranged, punk_health, punk_fear, punk_strength, punk_agility, punk_luck, punk_speed, punk_distance, punk_punch_attempt, punk_kick_attempt, punk_hit, punk_miss, punk_running, punk_territory, punk_attack_fail);	
	
}





void movement ()
{
	if (movement_action < 10)
		{
			movement_action++;
		}
	else
		{
			movement_action = 0;
		}
}

void dark_alley ()
{
	using namespace std;
	
	cout << "Dark alley. A strange man is standing in your way. \n";
	cout << "1. Start a fight.\n";
	cout << "2. You run.\n";
	cout << "3. You walk past him.\n";
	
	cin >> action;
	
	if (action == 1 && luck == 0 && has_money < 10)
		{
		health = health - 50 + hand_to_hand;     // this will cause healing during combat when hand_to_hand > 50
		++insanity;
		++nerves;
		hand_to_hand = hand_to_hand + 0.001;
		--empathy;
		++has_money;
		cout << "That hurt!.\n";
		}
	else if (action == 1 && luck > 0 && has_money > 9)
		{
		health = health - 50 + hand_to_hand;     // this will cause healing during combat when hand_to_hand > 50
		++insanity;
		++nerves;
		hand_to_hand = hand_to_hand + 0.001;
		--empathy;
		++quarter;
		has_money = 0;
		cout << "That hurt! But it's nice doing business with you.\n";
		}
	else if (action == 1 && luck == 0 && has_money > 9)
		{
		health = health - 50 + hand_to_hand;     // this will cause healing during combat when hand_to_hand > 50
		++insanity;
		++nerves;
		hand_to_hand = hand_to_hand + 0.001;
		--empathy;
		++has_money;
		cout << "That hurt!.\n";
		}
		
	else if (action == 1 && luck > 0 && has_money < 10)
		{
		health = health - 50 + hand_to_hand;     // this will cause healing during combat when hand_to_hand > 50
		++insanity;
		++nerves;
		hand_to_hand = hand_to_hand + 0.001;
		--empathy;
		++has_money;
		cout << "That hurt!.\n";
		}
		
	else if (action == 2)
		{
		stamina = stamina + 0.0001;
		++fear;
		++has_money;
		speed = speed + 0.0001;
		}
	else
		++nerves;
		++has_money;
		
	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
}

void kitten ()
{
	using namespace std;
	
	double health_agility_loss = 0;
	double health_strength_loss = 0;
	
	cout << "You come across a kitten that cannot get down from the tree. \n";
	cout << "1. Help the cat. \n";
	cout << "2. Move along. \n";
	
	cin >> answer;
	
	if (answer == '1')
	{
		if (agility > 0.01 && strength > 0.01)
			{
				cout << "You have helped the kitten!\n";
				agility = agility + 0.00001;
				strength = strength + 0.00001;
			}
		else
			{	
				if (agility < 0.01)
				health_agility_loss = (0.01 - agility);
				
				if (strength < 0.01)
				health_strength_loss = (0.01 - strength);
				
				health = health - health_agility_loss - health_strength_loss;
				cout << "You failed to help the kitten. You fell and received " << health_agility_loss + health_strength_loss << " worth of damage.\n";
				agility = agility + 0.0001;
				strength = strength + 0.0001;
			}
	}
	else
	{
		cout << "Sorry little cat. I'm not sure I can help. \n";
		++fear;
	}
	
	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
	
}

void gym ()
{
	using namespace std;
	
	cout << "Welcome to the Gym! \n";
	cout << "1. Take a fighting lesson.\n";
	cout << "2. Maybe tomorrow.\n";
	cout << "3. Work-out! \n";
	cout << "4. Run on a threadmill. \n";
	
	cin >> action;
	
	if (action == 1 && quarter > 0)
		{
		health = health - 10 + hand_to_hand;     // this will cause healing during combat when hand_to_hand > 10
		++nerves;
		hand_to_hand = hand_to_hand + 0.01;
		agility = agility + 0.001;
		stamina = stamina + 0.002;
		--quarter;
		cout << "That hurt! But I feel that I learned something.\n";
		}
	else if (action == 2)
		{
			cout << "Maybe later. \n";
		}
	else if (action == 1 && quarter == 0)
		{
			cout << "Retrun when you get some coin. \n";
		}
	else if (action == 3 && quarter > 0)
		{
		cout << "My muscles are sore today! \n";
		strength = strength + 0.001;
		--quarter;
		}

	else if (action == 3 && quarter == 0)
		{
			cout << "Retrun when you get some coin. \n";
		}
		
	else if (action == 4 && quarter > 0)
		{
		cout << "My legs are sore today! \n";
		stamina = stamina + 0.001;
		speed = speed + 0.0001;
		--quarter;
		}
		
	else if (action == 4 && quarter == 0)
		{
			cout << "Retrun when you get some coin. \n";
		}
		
	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
}

void running_dog ()

{
	using namespace std;
	double dog_stamina = 0.1;
	double dog_nerves = 10;
	
	cout << "You come across a dog barking and running towards you! \n";
	cout << "1. You run. \n";
	cout << "2. You charge towards the dog. \n";
	
	cin >> action;
	
	if (action == 1)
	all_dog_stamina (dog_stamina);
	if (action == 2)
	all_dog_nerves (dog_nerves);
	
}

bool all_dog_nerves (double param_dog_nerves)
{
	if (param_dog_nerves > nerves)
	{
	health = health - 10;
	++fear;
	cout << "The dog bit you in the REDACTED! \n";
	}
	else
	{
	cout << "You intimidated the dog! \n";
	++nerves;
	}
	
	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
	
}

bool all_dog_stamina (double param_dog_stamina)

{
	if (param_dog_stamina > stamina_used)
	{
	health = health - 10;
	cout << "The dog bit you in the REDACTED! \n";
	}
	else
	{
	stamina_used = stamina_used - param_dog_stamina;
	cout << "The dog got tired chasing after you! \n";
	cout << "Now go dry your pants! \n";
	}
	
	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
}

void barking_dog ()

{

	using namespace std;
	
	cout << "You come across a barking dog.\n";
	cout << "1. You run.\n";
	cout << "2. You walk past it.\n";
	cout << "3. You approach and caress it.\n";
	
	cin >> action;

	if (action == 1 && stamina != 0)
		{
		stamina = stamina + 0.001;
		++fear;
		speed = speed + 0.001;
		cout << "Wow! You're fast. Now go dry your pants.\n";
		}
	else if (action == 1 && stamina == 0)
		{
		health = health - 10;
		speed + 0.001;
		++fear;
		cout << "The dog bit you in the REDACTED!\n";
		}
	else if (action == 2)
		{
		++nerves;
		cout << "Sorry buddy! I've got no meat for you.\n";
		}

	else if (action == 3 && nerves > fear)
		{
		++empathy;
		++nerves;
		agility = agility + 0.001;
		cout << "That's a good dog!\n";
		}
	
	else if (action == 3 && fear > nerves)
		{
		health = health - 10;
		++fear;
		cout << "Ouch! My Hand!\n";
		}
	else
		{
		health = health - 10;
		++fear;
		cout << "Ouch! My Hand!\n";
		}
		
	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
}

void older_lady ()

{
	
	cout << "An older lady needs help with her shopping bags.\n";
	
	cout << "1. Carry them for her. \n";
	cout << "2. Walk by. \n";
	
	cin >> action;
	
	if (action == 1)
		{
			strength = strength + 0.001;
			speed = speed + 0.0001;
			cout << "These bags are quite heavy ma'am. What are you carrying? \n";
		}
	else
	{
	--empathy;
	cout << "Not my business.\n";
	}
	
	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
}

void money ()

{
	
	cout << "There is some money on the ground! \n";
	luck = luck + 0.01;
	
	cout << "1. Pick it up.\n";
	cout << "2. Walk by.\n";
	
	cin >> action;
	
	if (action == 1)
		{
			for (int i = 0; i < luck; ++i)
			quarter = quarter + 1;
			agility = agility + 0.001;
			strength = strength + 0.0001;
		}
	else
	{
	++empathy;
	cout << "Someone might come back for it. \n";
	}
	
	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
}

	void shop ()
	
{	
	
	cout << "You've come across a shop!\n";
	cout << "You can: \n";
	cout << "1. Buy a cookie for " << cookie_price [0] << ". \n";
	cout << "2. Browse goods. \n";
	cout << "3. Leave. \n";
	
	cin >> action;
	
	if (action == 1 && quarter > 0)
		{
			health = health + cookie [0];
			++mood;
			quarter = quarter - cookie_price [0];
			cout << "Food's good for you. \n";
		}
	
	else if (action == 1 && quarter == 0 && luck == 0 && mood <10)
		{
			cout << "No poors allowed! \n";
			++mood;
		}
		
	else if (action == 1 && quarter == 0 && luck > 0 && mood > 9)	
		{
			health = health + luck;
			mood = 0;
			cout << "Sharing is caring, right? You're acutally just lucky I'm in a mood. \n";
		}
	else if (action == 2 && quarter == 0 && luck > 0 && mood > 9)	
		{
			health = health + luck;
			mood = 0;
			cout << "Sharing is caring, right? You're acutally just lucky I'm in a mood. \n";
		}
	else if (action == 2 && quarter > 0)
		{
			cout << "1. Buy a cookie for " << cookie_price [0] << " quarter.\n";
			cout << "2. Buy " << cookie [1] << " cookies for " << cookie_price [1] << " quarters.\n";
			cout << "3. Buy " << cookie [2] << " cookies for " << cookie_price [2] << " quarters.\n";
			cout << "4. Buy " << cookie [3] << " cookies for " << cookie_price [3] << " quarters.\n";
			cout << "5. Buy " << cookie [4] << " cookies for " << cookie_price [4] << " quarters.\n";
			
			cin >> action2;
			if (action2 == 1 && quarter >= cookie_price [0])
			{
				health = health + cookie [0];
				++mood;
				quarter = quarter - cookie_price [0];
				cout << "Food's good for you. \n";
			}
			else if (action2 == 2 && quarter >= cookie_price [1])
			{
				health = health + cookie [1];
				++mood;
				quarter = quarter - cookie_price [1];
				cout << "Buying in bulk saves you quarters! \n";
			}
			else if (action2 == 3 && quarter >= cookie_price [2])
			{
				health = health + cookie [2];
				++mood;
				quarter = quarter - cookie_price [2];
				cout << "Buying in bulk saves you quarters! \n";
			}
			else if (action2 == 4 && quarter >= cookie_price [3])
			{
				health = health + cookie [3];
				++mood;
				quarter = quarter - cookie_price [3];
				cout << "Buying in bulk saves you quarters! \n";
			}
			else if (action2 == 5 && quarter >= cookie_price [4])
			{
				health = health + cookie [4];
				++mood;
				quarter = quarter - cookie_price [4];
				cout << "Buying in bulk saves you quarters! \n";
			}
			else
				cout << "Come back when you get more coin. \n";
		}
	
	else if (action == 3)
		{
			cout << "You'll be back though, right? \n";
		}
	else
		{
		++mood;
		cout << "No poors allowed! \n";
		}
	
	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
	
}


	void drop_weapon ()
	{
		cout << "You are currently wielding another weapon! \n";
		cout << "To drop the weapon press 'D'";
		cin >> answer;
		if (answer == 'D' || 'd')
		{
			agility = agility + penalty_agility_weapon;
			penalty_agility_weapon = 0;
						
			strength = strength - boost_strength_weapon;
			boost_strength_weapon = 0;
						
			melee = 0;
		}
		else
			cout << "You're holding to your weapon. \n";
	}


	void rock_event ()
	{
		using namespace std;
		
		cout << "You came across a small stone. \n";
		cout << "1. Pick it up. \n";
		cout << "2. Leave it. \n";
		
		cin >> answer;
		
		if (answer == '1')
		{
			cout << "You've picked up a stone \n" << endl;
			++rock;
			agility = agility + 0.0001;
			strength = strength + 0.0001;
			
			if (weapon != "rock")
			{
				cout << "Do you want to equip it? \n";
				cout << "1. Yes. \n";
				cout << "2. Maybe later. \n";
				
				cin >> answer;
				
				if (answer == '1')
				{
					equip_your_weapon();
				}
				else if (answer != '1')
					cout << "You have the rock in your inventory. \n";
			}
			
		}
		else
			cout << "I'll wait for more content. \n";

	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}

	}
	
	void hammer_event ()
	{
		using namespace std;
		
		cout << "You come across a small hammer. \n";
		cout << "1. Pick it up. \n";
		cout << "2. Leave it. \n";
		
		cin >> answer;
		
		if (answer == '1')
		{
			cout << "You've picked up the small hammer \n" << endl;
			++hammer;
			agility = agility + 0.0001;
			strength = strength + 0.0001;
			
			if (weapon != "hammer")
			{
				cout << "Do you want to equip it? \n";
				cout << "1. Yes. \n";
				cout << "2. Maybe later. \n";
				
				cin >> answer;
				
				if (answer == '1')
				{
					equip_your_weapon();
				}
				else if (answer != '1')
					cout << "You have the hammer in your inventory. \n";
			}
		}
		else
			cout << "I'll wait for more content. \n";

	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}

	}
	
	void equip_your_weapon ()
	{
		cout << "Type in the name of the weapon you want to use: \n";
		cout << "hand to hand? ";
		if (rock > 0)
		cout << "rock? ";
		if (hammer > 0)
		cout << "hammer? ";
	
		cin >> weapon;
	
	
	
		if (weapon == "rock")
		{
			weapon_rock ();
		}
		else if (weapon == "none")
		{
			weapon_none ();
		}
		else if (weapon == "hammer")
		{
			weapon_hammer ();
		}
		else
		{
			cout << "There is no such weapon";
			weapon_none ();
		}
	}
	
	void weapon_rock ()
	{
		melee = 1;
		mass = 1;
		weapon_quantity = rock;
		
		if (weapon_quantity == 0)
		{
			weapon_none ();
		}
		else
		cout << "You have eqquiped a rock! \n";
	}
	
	void weapon_none ()
	{
		melee = 0;
		mass = 1;
		weapon_quantity = 0;
		weapon = "hand to hand";
		
		cout << "You do not have any weapon equipped. \n";
	}
	
	void weapon_hammer ()
	{
		melee = 1;
		mass = 2;
		weapon_quantity = hammer;
		
		if (weapon_quantity == 0)
		{
			weapon_none ();
		}
		else
		cout << "You have eqquiped a hammer! \n";
	}
	

	void city ()
	{
		using namespace std;
		char ch_stats;
		char ch_map;
		
		while (quarter < 100)
		{
			
		///// cout << "Press 'S' to view your stats. \n";
		//////cin >> ch_stats;
		////////if (ch_stats == 'S' || ch_stats == 's')
		stats();
		
		/////////cout << "Press 'M' to view the map. \n";
		//////////cin >> ch_map;
		//////////if (ch_map == 'M' || ch_map == 'm')
		for_map();
		
		path = 1;
		
		cout << "To walk north press 'i'. \n";
		cout << "To walk south press 'k'. \n";
		cout << "To walk east press 'l'. \n";
		cout << "To walk west press 'j'. \n";
		
		if (posy == 0 && posx == 0)
		cout << "1. You can go back home.";
		else if (posx == -2 && posy == -2)
		cout << "1. You can go shopping.";
		else if (posx == 2 && posy == 1)
		cout << "9. You've come across a gym.";
		else
		
		
		cout << "You can continue! \n";
		win_flag = 0;
///		else if (posy == 0 && posx == 1 && police_report_skinny_punk == 0)
///		{
///			skinny_punk2 ();
///		}
		
		cin >> direction;
		
		old_posx = posx;
		old_posy = posy;
		
		if (direction == 'i' || direction == 'I')
			++posy;
		else if (direction == 'k' || direction == 'K')
			--posy;
		else if (direction == 'l' || direction == 'L')
			++posx;
		else if (direction == 'j' || direction == 'J')
			--posx;
		else if (direction == '1')
			home();
		else if (direction == '9')			
			gym ();
		
		random ();
		
		
	//	cout << "X" << posx - 1 << "Y" << posy + 1 << 
		
		
		
		//cout << " "  << " " << " " << " " << " ";
		
		
		}
		
		
	//	if (posy == 0 && posx == 0)
	//	cout << "1. You can go back home.";
	//	else if (posy == 0 && posx == 1 && police_report_skinny_punk == 0)
	//	{
	//		skinny_punk ();
	//	}
		
	}

void for_map ()
{
	for (int i = 10; i > -map_y; --i)
		{
		cout << "\n";
		for (int j = -10; j < map_x; ++j)
			{
				if (posx == j && posy == i)
					{
						if (j == 0 && i == 0)
						{
							cout << "[HXH]";
						}
						else if (j == 2 && i == 1)
						{
							cout << "[GXG]";
						}
						else	
							{
							cout << "[ X ]";
							}
							
					}
				else
					{
						if (j == 0 && i == 0)
						{
							cout << "[H H]";
						}
						else if (j == 2 && i == 1)
						{
							cout << "[G G]";
						}
						else
						{
							cout << "[   ]";
						}
						
					}	
			}
			
		}
		
}

	void home ()

{
	
	cout << "You can:\n";
	cout << "1. Go home.\n";
	cout << "2. Roam the city.\n";
	cout << "3. Save game.\n";
	cout << "4. Navigate the city. \n";
	
	cin >> action;
	
	if (action == 1 && health < 100)
		{
		for (int i = 0; i < stamina; ++i)
			{
			health = health + 1;
			}
			cout << "Home. Bed. Zzzzzz.\n";
			
		for (int i = 0; i < health && stamina_used < stamina; ++i)	
			{
			stamina_used = stamina_used + 0.0001;
			}
			cout << "You woke up regenrated. \n";
			
	
		}
	else if (action == 1 && stamina_used < stamina)
		{
			for (int i = 0; i < health && stamina_used < stamina; ++i)	
			{
			stamina_used = stamina_used + 0.001;
			cout << "You woke up regenrated. \n";
			}
		}
	else if (action == 1)
		cout << "Home! Sweet home!\n";
	else if (action == 3)
		{
		cout << "Do you want to make a new save? If Yes, press 'Y'";
		cin >> new_answer;
		save_specific (new_answer);
		}
	else if (action == 4)
		{
		path = 1;
		city ();
		}
	else
		{
			path = 0;
			random ();
		}
		
	
		
	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
}




	void stats ()
{
	if (short_combat_stats == 1)
	{
	
	cout << "\n";
	
	cout << "Health " << health << "\t"; cout << "Strength " << strength << "\t"; cout << "Agility " << agility << "\t"; cout << "Speed " << speed << "\n";
	cout << "-------------------------\n";
	cout << "Hand to Hand " << hand_to_hand << "\n";
	cout << "-------------------------\n";
	cout << "Currently equipped weapon: " << weapon << "\n";
	if (rock > 0) cout << "Rocks " << rock << "\t"; if (hammer > 0) cout << "Hammers " << hammer; cout << "\n";
	cout << "\n";
	}
	else
	{
	cout << "\n";
	cout << "Your stats are:\n";
	cout << "\n";
	cout << "Name: " << name_character << "\t"; cout << "Age: " << age << "\n";
	cout << "-------------------------\n";
	cout << "Health " << health << " " << &health << "\n";
	cout << "Stamina " << stamina_used << " out of " << stamina << "\t" << "Speed " << speed << " " << &speed << "\n";
	cout << "Strength " << strength << " " << &strength <<"\t"; cout << "Agility " << agility << " " << &agility << "\n";
	cout << "-------------------------\n";
	cout << "Hand to Hand " << hand_to_hand << "\n";
	cout << "-------------------------\n";
	cout << "Nerves " << nerves << "\t"; cout << "Fear " << fear << "\n";
	cout << "Insanity " << insanity << "\t"; cout << "Empathy " << empathy << "\n";
	cout << "Luck " << luck << "\n";
	cout << "-------------------------\n";
	cout << "Quarters " << quarter << "\n";
	cout << "Currently equipped weapon: " << weapon << "\n";
	if (rock > 0) cout << "Rocks " << rock << "\t"; if (hammer > 0) cout << "Hammers " << hammer; cout << "\n";
	cout << "-------------------------\n";
	cout << "Postion X" << posx << "\t"; cout << "Position Y" << posy << "\n";
	cout << "\n";
	}
}

void stats_ref (double & ref3_punk_distance)
{
	if (short_combat_stats == 1)
	{
	
	cout << "\n";
	
	cout << "Health " << health << "\t"; cout << "Strength " << strength << "\t"; cout << "Agility " << agility << "\t"; cout << "Speed " << speed << "\n";
	cout << "-------------------------\n";
	cout << "Hand to Hand " << hand_to_hand << "\n";
	cout << "-------------------------\n";
	cout << "Currently equipped weapon: " << weapon << "\n";
	if (rock > 0) cout << "Rocks " << rock << "\t"; if (hammer > 0) cout << "Hammers " << hammer; cout << "\n";
	cout << "Distance from the oponent: " << ref3_punk_distance << "\n";
	cout << "\n";
	}
	else
	{
	cout << "\n";
	cout << "Your stats are:\n";
	cout << "\n";
	cout << "Name: " << name_character << "\t"; cout << "Age: " << age << "\n";
	cout << "-------------------------\n";
	cout << "Health " << health << " " << &health << "\n";
	cout << "Stamina " << stamina_used << " out of " << stamina << "\t" << "Speed " << speed << " " << &speed << "\n";
	cout << "Strength " << strength << " " << &strength <<"\t"; cout << "Agility " << agility << " " << &agility << "\n";
	cout << "-------------------------\n";
	cout << "Hand to Hand " << hand_to_hand << "\n";
	cout << "-------------------------\n";
	cout << "Nerves " << nerves << "\t"; cout << "Fear " << fear << "\n";
	cout << "Insanity " << insanity << "\t"; cout << "Empathy " << empathy << "\n";
	cout << "Luck " << luck << "\n";
	cout << "-------------------------\n";
	cout << "Quarters " << quarter << "\n";
	cout << "Currently equipped weapon: " << weapon << "\n";
	if (rock > 0) cout << "Rocks " << rock << "\t"; if (hammer > 0) cout << "Hammers " << hammer; cout << "\n";
	cout << "-------------------------\n";
	cout << "Postion X" << posx << "\t"; cout << "Position Y" << posy << "\n";
	cout << "\n";
	}
}

void delay ()
{
	using namespace std;
	
	char any;
	cout << "Now it's time for some excersise! \n";
	float secs;
	secs = 5;
	clock_t delay = secs * CLOCKS_PER_SEC;
	
	clock_t start = clock ();
	while (clock () - start < delay)
		{
			cin.get (any);
			if (any == '\n')
			{
				health = health + 1;
			}
			
		}
		;
		
	cout << secs << " seconds have passed. \n";
	

	stats ();
	if (path == 0)
		random ();
		else if (path == 1)
			{
				win_flag = 1;
				cin.get();
				city();
			}
}


	void you_missed ()
	{
		cout << "###############\n";
		cout << "# You missed! #\n";
		cout << "###############\n";
		agility = agility + 0.001;
		hand_to_hand = hand_to_hand + 0.001;
		speed += 0.0001;
	}


	void save ()

{
	
	ofstream outsave;
		
	outsave.open("save_out.dat");
	outsave << health << endl << exp << endl << stamina <<
			endl << nerves << endl << insanity << endl <<
			hand_to_hand << endl << fear << endl <<
			empathy << endl << luck << endl << quarter << endl <<
			mood << endl << agility << endl << strength << endl <<
			age << endl << name_character << endl << speed;
		
	outsave.close();
	
}


	void save_specific (char)
	
{

while (new_answer == 'Y' || new_answer == 'y')
{	
	cout << "Type in the name of the file but not longer than 14 characters: \n";
	cin >> new_save;
	
	ofstream outsave_spec;
	
	outsave_spec.open(new_save);
	outsave_spec << health << endl << exp << endl << stamina <<
			endl << nerves << endl << insanity << endl <<
			hand_to_hand << endl << fear << endl <<
			empathy << endl << luck << endl << quarter << endl <<
			mood << endl << agility << endl << strength << endl <<
			age << endl << name_character << endl << speed;
			
	outsave_spec.close();
	cout << "Game has been saved to " << new_save << endl << "\n";
	home ();
	} 




}




