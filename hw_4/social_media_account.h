#ifndef SOCIAL_MEDIA_ACCOUNT_H
#define SOCIAL_MEDIA_ACCOUNT_H

#include <iostream>

const int maxFollowers = 10;
const int maxFollowed = 10;

template <typename T>
class SocialMediaAccount
{
	public:
		SocialMediaAccount(T handler, int followerCount, int followedCount, bool isPrivate)
		{
			this->handler = handler;
			this->followerCount = followerCount;
			this->followedCount = followedCount;
			this->isPrivate = isPrivate;
		}

		int getFollowerCount()
		{
			return this->followerCount;
		}

		void setFollowerCount(int followerCount)
		{
			this->followerCount = followerCount;
		}

		int getFollowedCount()
		{
			return this->followedCount;
		}

		void setFollowedCount(int followedCount)
		{
			this->followedCount = followedCount;
		}

		void addFollower(T follower)
		{
			if (this->followerCount >= maxFollowers)
			{
				return;
			}

			this->followers[this->followerCount++] = follower;
		}

		void addFollowed(T followed)
		{
			if (this->followedCount >= maxFollowed)
			{
				return;
			}

			this->followed[this->followedCount++] = followed;
		}

		void displayFollowers()
		{
			if (this->isPrivate)
			{
				std::cout << "Cannot display followers because account is private\n\n";
			}
			else
			{
				for (int i = 0; i < this->followerCount; ++i)
				{
					std::cout << this->followers[i] << "\n";
				}

				std::cout << "\n";
			}
		}

		void displayFollowed()
		{
			if (this->isPrivate)
			{
				std::cout << "Cannot display followed because account is private\n\n";
			}
			else
			{
				for (int i = 0; i < this->followedCount; ++i)
				{
					std::cout << this->followed[i] << "\n";
				}

				std::cout << "\n";
			}
		}

	private:
		T handler;
		T followers[maxFollowers];
		T followed[maxFollowed];
		int followerCount;
		int followedCount;
		bool isPrivate;
};

#endif