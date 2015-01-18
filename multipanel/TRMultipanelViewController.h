//
//  TrMultipanelViewController.h
//  tvoirecepty
//
//  Created by Vitaly on 3/23/14.
//  Copyright (c) 2014 tvoirecepty. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TRMultipanelViewController;

extern NSString* const TRMultipanelDidShowSideNotification;
extern NSString* const TRMultipanelDidHideSideNotification;
extern NSString* const TRMultipanelDidToggleSideNotification;

typedef NS_ENUM(NSInteger, TRMultipanelSideType) {
    TRMultipanelSideTypeUnknown,
    TRMultipanelSideTypeLeft,
    TRMultipanelSideTypeRight
};

@protocol TRMultipanelViewControllerDelegate <NSObject>

@optional
- (BOOL)multipanel:(TRMultipanelViewController*)multipanel side:(TRMultipanelSideType)sideType shouldReceiveTouch:(UITouch *)touch;

@end

@interface TRMultipanelViewController : UIViewController

@property (weak, nonatomic) id<TRMultipanelViewControllerDelegate> delegate;
@property (strong, nonatomic) UIView* centerView;

- (UIViewController*)contentControllerForSide:(TRMultipanelSideType)side;
- (void)setContentController:(UIViewController*)controller forSide:(TRMultipanelSideType)side;

- (BOOL)isVisibleSide:(TRMultipanelSideType)side;

- (CGFloat)widthForSide:(TRMultipanelSideType)side;
- (void)setWidth:(CGFloat)width forSide:(TRMultipanelSideType)side;

- (void)showSide:(TRMultipanelSideType)side
        animated:(BOOL)animated;

 - (void)hideSide:(TRMultipanelSideType)side
         animated:(BOOL)animated;

- (void)toggleSide:(TRMultipanelSideType)side
          animated:(BOOL)animated;

- (void)showSide:(TRMultipanelSideType)sideType
        animated:(BOOL)animated
      completion:(void (^)(TRMultipanelSideType sideType, BOOL finished))completionBlock;

- (void)hideSide:(TRMultipanelSideType)sideType
        animated:(BOOL)animated
      completion:(void (^)(TRMultipanelSideType sideType, BOOL finished))completionBlock;

- (void)toggleSide:(TRMultipanelSideType)sideType
          animated:(BOOL)animated
        completion:(void (^)(TRMultipanelSideType sideType, BOOL finished))completionBlock;
@end
