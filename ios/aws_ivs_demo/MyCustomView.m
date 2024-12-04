//
//  CustomView.m
//  
//
//  Created by dev on 12/4/24.
//

#import <React/RCTViewManager.h>

@interface RCT_EXTERN_MODULE(RCTMyCustomViewManager, RCTViewManager)
RCT_EXPORT_VIEW_PROPERTY(status, BOOL)
RCT_EXPORT_VIEW_PROPERTY(onClick, RCTBubblingEventBlock)
@end

