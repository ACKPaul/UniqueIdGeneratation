##To design a unique ID generator based on the Twitter snowflake ID generator approach for distributed systems, we need to consider several key aspects:

## Components of the Unique ID Generator

##Datacenter ID and Machine ID:
These IDs are chosen at startup and are typically fixed once the system is operational. They identify the datacenter and the specific machine within that datacenter where the ID is generated.
Changing these IDs after deployment requires careful planning to avoid ID conflicts.

##Timestamp:
The timestamp component represents the time at which the ID is generated.
Ensuring a consistent and unique timestamp across the system is crucial to prevent ID collisions.

##Sequence Number:
In cases where multiple IDs are generated within the same timestamp, a sequence number ensures uniqueness.
It resets to zero whenever the timestamp changes to maintain uniqueness over time.

#Design Considerations
##Datacenter and Machine ID Configuration:
Implement a mechanism to configure and validate these IDs at startup to ensure they are unique and correctly assigned.
Consider using configuration files or environment variables for flexibility and ease of deployment.

##Timestamp Management:
Use a reliable time source to generate timestamps. This can be system time, but care should be taken to handle clock skew in distributed environments.
Consider using a monotonic clock to avoid issues with time adjustments.

##Sequence Number Handling:
Ensure that the sequence number increments correctly and resets appropriately when the timestamp changes.
Implement a mechanism to handle high-frequency ID generation without compromising uniqueness.



## Build And Test
mkdir build 

cd build

cmake -G "MinGW Makefiles" ..

mingw32-make


