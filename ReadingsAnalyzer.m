//
//  ReadingsAnalyzer.m
//  WorkoutLogger
//
//  Created by Kwame Efah  on 5/6/16.
//  Copyright © 2016 Sam Madden. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ReadingsAnalyzer.h"
#import "SensorReading.h"


static id _instance;
@implementation ReadingsAnalyzer {
}

-(id) init {
    self = [super init];
    if (self) {
        //TODO: Initialize instance variables
        
        
    }
    return self;
}

-(NSInteger) countRepetitionsFromLeft:(NSArray *)leftSensorReadings andRight:(NSArray *)rightSensorReadings {
    
    NSMutableArray* rawXAccelValues = [[NSMutableArray alloc] init];
    for (int i = 0; i < [leftSensorReadings count]; i++) {
        NSArray* accelValues = [leftSensorReadings[i] accelReadings];
        [rawXAccelValues addObject:accelValues[0]];
    }
    
    //Low pass filter raw acceleration values
    
    NSArray *filteredAccelValues = [self filterAccelerationData:rawXAccelValues];
    
    //NSNumber *zeroCrossings = [self countZeroCrossings:filteredAccelValues];
    
    return zerocrossings / 2;
}

- (NSArray*) filterAccelerationData: (NSArray*) rawValues {
    
    //Implement low pass filter
    double rate = 10;
    double freq = 1.0;
    double dt = 1.0 / rate;
    double RC = 1.0 / freq;
    double filterConstant = dt / (dt + RC);
    
    NSMutableArray *filteredValues = [[NSMutableArray alloc] init];
    for (int i = 0; i < [rawValues count]; i++) {
        int filteredValue = (int16_t) rawValues[i] * filterConstant + (int16_t)rawValues[i-1] * (1.0 - filterConstant);
        [filteredValues addObject: [NSNumber numberWithInt:filteredValue]];
    }
    return filteredValues;
}

- (NSNumber*) countZeroCrossings: (NSArray*) signal {
    NSNumber lastValue = signal[0];
    int numZeroCrossings = 0;
    for (int i = 1; i < [signal count]; i++) {
        NSNumber currentValue = signal[i];
        //check if we crossed zero and increment
        
    }
    
}
@end