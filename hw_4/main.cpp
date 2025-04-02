/*
	Nolan Hughes
	CSC-275
	HW 4
	Due 4/9/2025
*/

#include <iostream>
#include <string>

#include "instagram.h"
#include "twitter.h"

struct Profile
{
	int userId;
	std::string username;

	friend std::ostream &operator <<(std::ostream &stream, const Profile &profile)
	{
		stream << "UserId: " << profile.userId << " | username: " << profile.username;
	}
};

int main()
{
	std::string twitterString = "Nolan";
	Profile twitterProfile =
	{
		.userId = 0,
		.username = "Finn"
	};

	std::string instagramString = "Brady";
	Profile instagramProfile =
	{
		.userId = 1,
		.username = "Hughes"
	};

	Twitter<std::string> ts(twitterString, 0, 0, false);
	Twitter<Profile> tp(twitterProfile, 0, 0, true);

	Instagram<std::string> is(instagramString, 0, 0, true);
	Instagram<Profile> ip(instagramProfile, 0, 0, false);

	ts.addFollower("profile1");
	ts.displayFollowers();

	tp.addFollowed((Profile){2, "profile2"});
	tp.displayFollowers();

	is.addFollowed("profile3");
	is.displayFollowed();

	ip.addFollower((Profile){3, "profile4"});
	ip.displayFollowers();

	return 0;
}