//
//  GuideDetailViewController.h
//  iNaturalist
//
//  Created by Ken-ichi Ueda on 9/4/13.
//  Copyright (c) 2013 iNaturalist. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Guide.h"
#import "DejalActivityView.h"
#import "RXMLElement.h"

@interface GuideDetailViewController : UICollectionViewController
{
    DejalActivityView *modalActivityView;
}
@property (nonatomic, strong) Guide *guide;
@property (nonatomic, strong) NSMutableData *ngzData;
@property (nonatomic, strong) NSString *guideDirPath;
@property (nonatomic, strong) NSString *guideXMLPath;
@property (nonatomic, strong) RXMLElement *xml;
@property (nonatomic) CGFloat scale;

- (void)loadXML:(NSString *)path;
- (void)downloadXML:(NSString *)url;
- (void)downloadNGZ:(NSString *)url;
@end

@interface XMLDownloadDelegate : NSObject <NSURLConnectionDelegate>
@property (nonatomic, strong) UIProgressView *progress;
@property (nonatomic, strong) NSMutableData *receivedData;
@property (nonatomic) long expectedBytes;
@property (nonatomic, strong) DejalActivityView *dejalActivityView;
@property (nonatomic) NSInteger lastStatusCode;
@property (nonatomic, strong) NSString *filePath;
@property (nonatomic, strong) GuideDetailViewController *controller;

- (id)initWithController:(GuideDetailViewController *)controller;

@end