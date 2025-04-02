#ifndef INSTAGRAM_H
#define INSTAGRAM_H

#include "social_media_account.h"

template <typename T>
class Instagram : public SocialMediaAccount<T>
{
	public:
		Instagram(T handler, int followerCount, int followedCount, bool isPrivate) : SocialMediaAccount<T>(handler, followerCount, followedCount, isPrivate)
		{
			this->likeCount = 0;
		}

		int getLikeCount()
		{
			return this->likeCount;
		}

		void setLikeCount(int likeCount)
		{
			this->likeCount = likeCount;
		}

		void like()
		{
			++this->likeCount;
		}

	private:
		int likeCount;
};

#endif