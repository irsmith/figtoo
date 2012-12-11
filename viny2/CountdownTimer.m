//
//  CountdownTimer.m
//  viny2
//
//  Created by Smith, Irene S. (ARC-TI)[Stinger Ghaffarian Technologies Inc. (SGT Inc.)] on 12/3/12.
//  Copyright (c) 2012 Smith, Irene S. (ARC-TI)[Stinger Ghaffarian Technologies Inc. (SGT Inc.)]. All rights reserved.
//

#import "CountdownTimer.h"
#import "DateUtils.h"

@implementation CountdownTimer

@synthesize start, end;
@synthesize delegate1;


NSTimer *timerA;
int elapsedTimeSeconds;
bool startA = TRUE; //  disallows multiple timers
int counterA;


// Next 2 methods are the timer and its local callback (a selector). 
-(void)timerTicked {
    NSDateComponents *elapsedAsInterval = [DateUtils getComponentsFromTimeInterval:elapsedTimeSeconds];
    
    //notify my observers
    NSString *hours = [NSString stringWithFormat:@"%02d", [elapsedAsInterval hour]];
    NSString *minutes = [NSString stringWithFormat:@"%02d", [elapsedAsInterval minute]];
    NSString *seconds = [NSString stringWithFormat:@"%02d", [elapsedAsInterval second]];
    
    [self.delegate1 firedWithHours:hours :minutes :seconds];

    elapsedTimeSeconds -= 1;
    
    if (elapsedTimeSeconds < 0) {
        
        [timerA invalidate];
        startA = TRUE;
    }
}

/**
 http://bradcupit.tumblr.com/post/3431169229/ios-blocks-vs-selectors-and-delegates
 */
-(void)startTimerWithStartTime:(NSDate *)startTime andDuration:(NSTimeInterval) duration{

    self.start = startTime;
    elapsedTimeSeconds = duration;
    
    if(startA == TRUE) //Check that another instance is not already running.
    {
        startA = FALSE;
        timerA = [NSTimer scheduledTimerWithTimeInterval:1.0 target:self selector:@selector(timerTicked) userInfo:nil repeats:YES];
    }
    
    
}


/* Returns the time interval from now, to when the task expires. */
-(NSTimeInterval *) timeUntilExpiration{
    return nil; //interval from counterNow to end
}

/* Returns the time counted down so far. */
-(NSTimeInterval *) timeCountedDownSoFar {
    return nil; // interval from this.start to counterNow
}



@end
