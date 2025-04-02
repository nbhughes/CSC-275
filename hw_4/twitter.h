#ifndef TWITTER_H
#define TWITTER_H

#include "social_media_account.h"

template <typename T>
class Twitter : public SocialMediaAccount<T>
{
	public:
		Twitter(T handler, int followerCount, int followedCount, bool isPrivate) : SocialMediaAccount<T>(handler, followerCount, followedCount, isPrivate)
		{
			this->retweetCount = 0;
		}

		int getRetweetCount()
		{
			return this->retweetCount;
		}

		void setRetweetCount(int retweetCount)
		{
			this->retweetCount = retweetCount;
		}

		void rt()
		{
			++this->retweetCount;
		}

	private:
		int retweetCount;
};

#endif