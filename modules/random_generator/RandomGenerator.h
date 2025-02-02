#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

class RandomGenerator {
    public:
        virtual ~RandomGenerator() = default;
        virtual int getRandomNumber(uint32_t* value) = 0;  // Pure virtual function
        virtual int devideByRandomNumber(int value) {
            /*
                Suppose you have a function divideByRandom that divides a given value 
                by a random denominator obtained from a random number generator.
                You want to ensure that your function correctly handles the case when the random number 
                generator returns zero. (Aim is to catch a divide-by-zero error case.)
            */
            uint32_t rnd_number = 0;
            getRandomNumber(&rnd_number);
            return static_cast<uint8_t>(value / rnd_number);
        };
};

class ZephyrRandomGenerator : public RandomGenerator {
    public:
        ZephyrRandomGenerator() {};
        int getRandomNumber(uint32_t* value) override;
};

#endif // RANDOM_GENERATOR_H