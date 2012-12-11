//
//  CountdownTimer.h
//  viny2
//
//  Created by Smith, Irene S. (ARC-TI)[Stinger Ghaffarian Technologies Inc. (SGT Inc.)] on 12/3/12.
//  Copyright (c) 2012 Smith, Irene S. (ARC-TI)[Stinger Ghaffarian Technologies Inc. (SGT Inc.)]. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TimerObserverDelegate<NSObject>
@required

- (void) firedWithHours: (NSString *)hours: (NSString *)minutes: (NSString *)seconds;
- (void) expired;
@end


@interface CountdownTimer : NSObject{
    /*
     Publish a  public entry point for the set delegate API. 
     CountdownTimer is using a no arg constructor.
     
     Three ways to manage callbacks
     http://bradcupit.tumblr.com/post/3431169229/ios-blocks-vs-selectors-and-delegates
     
     */
	id <TimerObserverDelegate> delegate;
    
}
@property (nonatomic, weak) NSDate *start; //taskRequestTime;
@property (nonatomic, weak) NSDate *end;   //taskExpirationTime;
@property (retain) id delegate1;

// publish a public entry point to start me up.
-(void)startTimerWithStartTime:(NSDate *)startTime andDuration:(NSTimeInterval) duration;
@end
