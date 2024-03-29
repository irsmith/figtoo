//
//  DetailViewController.h
//  viny2
//
//  Created by Smith, Irene S. (ARC-TI)[Stinger Ghaffarian Technologies Inc. (SGT Inc.)] on 11/23/12.
//  Copyright (c) 2012 Smith, Irene S. (ARC-TI)[Stinger Ghaffarian Technologies Inc. (SGT Inc.)]. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CountdownTimer.h"
#import <AudioToolbox/AudioToolbox.h>

@class ManualInstruction;
@class DetailViewController;

@protocol DetailViewControllerDelegate <NSObject>
- (void)didCancel:(DetailViewController *)controller;
- (void)didCompleteTask:(DetailViewController *)controller;
@end

@interface DetailViewController : UITableViewController <UISplitViewControllerDelegate, TimerObserverDelegate>
{
    
    CountdownTimer *countdownTimer; // todo move to weak property
    SystemSoundID taskDataReportedSound;
    SystemSoundID taskDoneSound;
    SystemSoundID taskExpirededSound;
    
}


/*
 Properties are an Objective-C 2.0 feature that allow you more effortless access to your instance variables.These configure the getter and setter methods 
// Strong ref to our detail item.
// Weak ref to the GUI elements.
// Identify these as outlets (like java property listeners).
 */
@property (nonatomic, strong) ManualInstruction *manualInstruction;
@property (nonatomic, weak) id <DetailViewControllerDelegate> delegate;
- (IBAction)handlePinch:(UIPinchGestureRecognizer *)recognizer;

@end

