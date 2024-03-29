//
//  PhotoViewController.h
//  viny2
//
//  Created by Smith, Irene S. (ARC-TI)[Stinger Ghaffarian Technologies Inc. (SGT Inc.)] on 11/30/12.
//  Copyright (c) 2012 Smith, Irene S. (ARC-TI)[Stinger Ghaffarian Technologies Inc. (SGT Inc.)]. All rights reserved.
//

@class ManualInstruction;

#import <UIKit/UIKit.h>

@interface PhotoViewController : UIViewController

@property (nonatomic, strong) ManualInstruction *manualInstruction;
@property (nonatomic, strong) IBOutlet UIImageView *imageView;
- (IBAction)handlePinch:(UIPinchGestureRecognizer *)recognizer;

@end
