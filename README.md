# User Login Notification
This module provides a **block and a ctools content type (pane)** that display the last time a user logged in. 

## Features
- Block is automatically assigned to the sidebar if any of the following regions are found:
    - left
    - sidebar_left
    - sidebar
- The time is always displayed in the logged in user's timezone.
- The block collapses automatically after 10 seconds.
- The block can be configured to display different message per role.
- The pane uses the _user_ context, which can be used to configure the logged in time for user defined in a context.

## Challenges
The block cannot be cached globally or by role because the logged in time is different for each user. The module uses ```DRUPAL_NO_CACHE``` because of the very personalized content. ```DRUPAL_CACHE_PER_USER``` cannot be used in this case because the _cache is not re-generated when the user logs in_.

## Solution
For granular control over the cache,```DRUPAL_CACHE_CUSTOM``` can be implemented so the block can regenerate the content when a user logs in.
