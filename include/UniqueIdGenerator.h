#include <iostream>
#include <chrono>

using Clock = std::chrono::steady_clock;

class UniqueIdGenerator
{
public:
    UniqueIdGenerator() = default;

    UniqueIdGenerator(int dataCentre, int machineNo, std::chrono::time_point<Clock> previousTime)
        : dataCentre(dataCentre), machineNo(machineNo), PreviousTime(previousTime) {}

    uint64_t getId()
    {
        // Reserve bit
        uint64_t uniqueId = 0;

        // First bit left as it

        // Second 41 bits for timestamp
        auto now = Clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(now - baseTimePoint).count();

        uniqueId |= static_cast<int>(time << 22);

        // Data centre
        uniqueId |= dataCentre << 17;

        // Machine Number
        uniqueId |= machineNo << 12;

        // Sequence Number
        uniqueId |= getSequenceNumber() & 0xFFF;

        return uniqueId;
    }

private:
    std::chrono::time_point<Clock> baseTimePoint = Clock::now();
    int reserveBit = 1;
    int dataCentre{};
    int machineNo{};
    std::chrono::time_point<Clock> PreviousTime = Clock::now();
    int sequenceNumber{};

    int getSequenceNumber()
    {
        auto now = Clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(now - PreviousTime).count();
        PreviousTime = now;
        if (time > 0)
        {
            sequenceNumber = 0;
        }
        else
        {
            sequenceNumber++;
        }

        return sequenceNumber;
    }
};


