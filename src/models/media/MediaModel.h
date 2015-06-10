//
//  MediaModel.h
//  ARIS
//
//  Created by Brian Thiel on 3/28/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Media.h"

@interface MediaModel : NSObject

- (id) initWithContext:(NSManagedObjectContext *)c;
- (Media *) mediaForId:(long)media_id;
- (Media *) newMedia;
- (void) requestMedia;
- (void) clearGameData;
- (BOOL) gameInfoRecvd;
- (void) clearCache;

- (void) saveAlteredMedia:(Media *)m; //don't like this...

@end
