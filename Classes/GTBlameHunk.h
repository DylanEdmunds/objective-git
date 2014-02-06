//
//  GTBlameHunk.h
//  ObjectiveGitFramework
//
//  Created by David Catmull on 11/6/13.
//  Copyright (c) 2013 GitHub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "git2.h"

@class GTOID;
@class GTSignature;

@interface GTBlameHunk : NSObject

- (instancetype)initWithGitBlameHunk:(git_blame_hunk)hunk;

// The number of lines in the hunk.
@property (nonatomic, readonly) NSUInteger lineCount;

// The OID of the commit where this hunk was last changed.
@property (nonatomic, readonly, copy) GTOID *finalCommitOID;

// The 1-based line number where this hunk begins, in the final version of the file.
@property (nonatomic, readonly) NSUInteger finalStartLineNumber;

// The signature of the commit where this hunk was last changed.
@property (nonatomic, readonly) GTSignature *finalSignature;

// The path of the file in the original commit.
@property (nonatomic, readonly, copy) NSString *originalPath;

// `YES` if the blame stopped trying before the commit where the line was added was found.
// This could happen if you use `GTBlameOptionsOldestCommitOID`.
@property (nonatomic, readonly) BOOL isBoundary;

// The git_blame_hunk represented by the receiver.
@property (nonatomic, readonly) git_blame_hunk git_blame_hunk;

@end
