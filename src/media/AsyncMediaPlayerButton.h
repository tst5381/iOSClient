//
//  AsyncMediaPlayerButton.h
//  ARIS
//
//  Created by David Gagnon on 2/4/12.
//  Copyright (c) 2012 University of Wisconsin. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol AsyncMediaPlayerButtonDelegate
@end

@class Media;

@interface AsyncMediaPlayerButton : UIButton
-(id)initWithFrame:(CGRect)frame media:(Media *)media presenter:(UIViewController *)p preloadNow:(BOOL)preload;
-(id)initWithFrame:(CGRect)frame mediaId:(int)mediaId presenter:(UIViewController *)p preloadNow:(BOOL)preload;
@end
